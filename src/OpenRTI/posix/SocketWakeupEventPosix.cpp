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

#include "SocketWakeupEvent.h"
#include "Exception.h"
#include "ErrnoPosix.h"
#include "SocketPrivateDataPosix.h"

namespace OpenRTI {

ssize_t
SocketWakeupEvent::read()
{
  char data[512];
  ssize_t ret = ::read(_privateData->_fd, data, sizeof(data));
  if (ret == -1) {
    int errorNumber = errno;
    if (errorNumber == EAGAIN || errorNumber == EINTR)
      return 0;
    throw TransportError(errnoToUcs(errorNumber));
  }
  
  if (ret == 0)
    return -1;
  return ret;
}

SocketWakeupEvent::SocketWakeupEvent(PrivateData* privateData) :
  Socket(privateData)
{
}

SocketWakeupEvent::~SocketWakeupEvent()
{
}

} // namespace OpenRTI
