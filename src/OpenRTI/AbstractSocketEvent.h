/* -*-c++-*- OpenRTI - Copyright (C) 2009-2011 Mathias Froehlich
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

#ifndef OpenRTI_AbstractSocketEvent_h
#define OpenRTI_AbstractSocketEvent_h

#include <string>
#include "Exception.h"
#include "LogStream.h"
#include "Referenced.h"
#include "SharedPtr.h"
#include "SocketEventDispatcher.h"
#include "SocketReadEvent.h"
#include "SocketWriteEvent.h"

namespace OpenRTI {

class OPENRTI_API AbstractSocketEvent : public Referenced {
public:
  // AbstractSocketEvent() :
  //   _timeout(Clock::final())
  // { }
  virtual ~AbstractSocketEvent();

  // Is called from the parent protocol layer when there is data to read
  virtual void read(SocketEventDispatcher& dispatcher);
  virtual bool getEnableRead() const = 0;

  // Is called from the parent protocol layer when there is space to write something
  virtual void write(SocketEventDispatcher& dispatcher);
  virtual bool getEnableWrite() const = 0;

  // Is called when the given timeout value expires.
  // virtual void timeout(SocketEventDispatcher& dispatcher)
  // { }

  // Is called when an unrecoverable error happens.
  virtual void error(const Exception& e);

  virtual Socket* getSocket() const = 0;

  /// Here we could also store a timeout value that is used for the poll/select timeout
  /// Since we need to traverse all active readwriteevents in any case this is not an extra effort.
  // const Clock& getTimeout() const
  // { return _timeout; }
  // void setTimeout(const Clock& timeout)
  // { _timeout = timeout; }

private:
  // Clock _timeout;
};

} // namespace OpenRTI

#endif