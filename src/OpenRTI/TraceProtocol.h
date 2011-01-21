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

#ifndef OpenRTI_TraceProtocol_h
#define OpenRTI_TraceProtocol_h

#include <map>
#include <string>
#include "AbstractProtocol.h"

namespace OpenRTI {

class Clock;

/// Protocol root factory for something that writes out traces of the communication.
class OPENRTI_LOCAL TraceProtocol : public AbstractProtocol {
public:
  virtual SharedPtr<AbstractConnect> connect(const std::map<std::wstring,std::wstring>& parameterMap, const Clock& abstime) const;

private:
  class MessageDispatcher;
  class MessageSender;
  class MessageReceiver;
  class Connect;
};

} // namespace OpenRTI

#endif
