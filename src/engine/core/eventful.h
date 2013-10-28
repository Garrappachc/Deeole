/*
 * eventful.h
 * Copyright (C) 2013  Michał Garapich <michal@garapich.pl>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 */

#ifndef EVENTFUL_H
#define EVENTFUL_H

#include <vector>

#include "core/deeglobal.h"

namespace Dee {
  
  class AbstractSignal;
  template <typename... Args> class Signal;
  
/**
 * \ingroup Core
 * @{
 * 
 * This is the base class for the signals-and-slots system.
 * 
 * In order to be able to implement your own slots you need to derive
 * this class.
 * 
 * \sa Signal.
 */
class __DeeExport__ Eventful {
  
  template <typename... Args>
    friend class Signal;
  
public:
  
  /**
   * The constructor.
   */
  Eventful() = default;
  
  /**
   * The destructor.
   * 
   * The destructor removes all connections.
   */
  virtual ~Eventful();
  
private:
  void addSender(AbstractSignal* sender);
  void removeSender(AbstractSignal* sender);
  
  void __disconnectAll();
  
  std::vector<AbstractSignal*> __senders;
  
}; /** @} */

} /* namespace Dee */

#endif // EVENTFUL_H
