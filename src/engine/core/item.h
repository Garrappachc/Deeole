/*
 * item.h
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

#ifndef ITEM_H
#define ITEM_H

#include "core/deeglobal.h"

#include "core/renderable.h"
#include "core/transformationmatrix.h"

namespace Dee {

class __DeeExport__ Item : public Renderable {
  
public:
  Item(bool visible = true);
  
  inline void rotate(float angle, Axis axis) {
    __matrix.rotate(angle, axis);
  }
  
protected:
  void render() override;
  
private:
  TransformationMatrix __matrix;
  
};

} /* namespace Dee */

#endif // ITEM_H
