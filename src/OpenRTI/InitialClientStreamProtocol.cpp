/* -*-c++-*- OpenRTI - Copyright (C) 2009-2012 Mathias Froehlich
 *
 * This file is part of OpenRTI.
 *
 * OpenRTI is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation, either version 2.1 of the License, or
 * (at your option) any later version.
 *
 * OpenRTI is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with OpenRTI.  If not, see <http://www.gnu.org/licenses/>.
 *
 */

#include "InitialClientStreamProtocol.h"

#include "LogStream.h"
#include "NetworkServer.h"
#include "MessageEncodingRegistry.h"
#include "NetworkServerConnect.h"
#include "ServerOptions.h"
#include "ZLibProtocolLayer.h"

namespace OpenRTI {

InitialClientStreamProtocol::InitialClientStreamProtocol(NetworkServer& networkServer) :
  _networkServer(networkServer),
  _successfulConnect(false)
{
}

InitialClientStreamProtocol::InitialClientStreamProtocol(NetworkServer& networkServer, const StringStringListMap& connectOptions) :
  _networkServer(networkServer),
  _successfulConnect(false)
{
  setConnectOptions(connectOptions);
}

InitialClientStreamProtocol::~InitialClientStreamProtocol()
{
}

void
InitialClientStreamProtocol::setConnectOptions(StringStringListMap connectOptions)
{
#if defined OPENRTI_ENCODING_DEVELOPMENT_WARNING
  Log(MessageCoding, Warning) << OPENRTI_ENCODING_DEVELOPMENT_WARNING << std::endl;
#endif

  // The rti version we support.
  connectOptions["version"].clear();
  connectOptions["version"].push_back(OPENRTI_ENCODING_VERSION);
  // The servers configuration might have configured compression algorithms
  // that are not available in this current version. Make sure these are
  // not announced to the server.
#if !defined(OPENRTI_HAVE_XZ)
  connectOptions["compression"].remove("lzma");
#endif
#if !defined(OPENRTI_HAVE_ZLIB)
  connectOptions["compression"].remove("zlib");
#endif
  // And all our encodings we can just do,
  connectOptions["encoding"] = MessageEncodingRegistry::instance().getEncodings();

  writeOptionMap(connectOptions);

  // Add space for the initial header
  addScratchReadBuffer(12);
}

void
InitialClientStreamProtocol::readOptionMap(const StringStringListMap& optionMap)
{
  // For now, just stop processing once we have recieved the connect reply
  _networkServer.setDone(true);

  // Check for an error response
  StringStringListMap::const_iterator i = optionMap.find("error");
  if (i != optionMap.end()) {
    if (i->second.empty())
      throw RTIinternalError("Error response from server without error message!");
    throw RTIinternalError(i->second.front());
  }

  i = optionMap.find("encoding");
  // This means 'if (1 < i->second.size())' without running into O(N) size with lists.
  if (i == optionMap.end() || i->second.empty())
    throw RTIinternalError("No encoding sent with server reponse!");
  if (1 < i->second.size())
    throw RTIinternalError("Non unique encoding sent with server reponse!");

  SharedPtr<AbstractMessageEncoding> messageProtocol;
  messageProtocol = MessageEncodingRegistry::instance().getEncoding(i->second.front());
  if (!messageProtocol.valid()) {
    throw RTIinternalError("Unable to do server given encoding!");
  }

  // FIXME May be get this from the Server?
  // This way we could get a connect that matches the network servers idea of threading?
  SharedPtr<NetworkServerConnect> connect = new NetworkServerConnect;
  connect->connectParent(_networkServer, optionMap);
  messageProtocol->setConnect(connect);

  // This is the part of the protocol stack that replaces this initial stuff.
  SharedPtr<AbstractProtocolLayer> protocolStack = messageProtocol;
  // Now decide what type of compression and checksumming happens in between.

  i = optionMap.find("compression");
  if (i != optionMap.end() && !i->second.empty()) {
    if (1 < i->second.size())
      throw RTIinternalError("Non unique compression sent with server response!");
    if (i->second.front() == "lzma") {
// #if defined(OPENRTI_HAVE_XZ)
//         SharedPtr<LZMACompressionProtocolLayer> layer = new LZMACompressionProtocolLayer;
//         layer->setProtocolLayer(protocolStack);
//         protocolStack = layer;
// #else
      throw RTIinternalError("Unable to do server given lzma compression!");
// #endif
    }
    if (i->second.front() == "zlib") {
#if defined(OPENRTI_HAVE_ZLIB)
      SharedPtr<ZLibProtocolLayer> layer = new ZLibProtocolLayer;
      layer->setProtocolLayer(protocolStack);
      protocolStack = layer;
#else
      throw RTIinternalError("Unable to do server given zlib compression!");
#endif
    }
  }

  _successfulConnect = true;
  setFollowupProtocol(protocolStack);
}

void
InitialClientStreamProtocol::error(const Exception& e)
{
  // On error with the parent connect also stop the connect attempt
  _networkServer.setDone(true);
  // Store the error description
  _errorMessage = e.getReason();
  _successfulConnect = false;
}

} // namespace OpenRTI
