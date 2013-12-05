/*
 * item.cpp
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

#include <GL/gl.h>

#include "item.h"

namespace Dee {

Item::Item(bool visible) :
    Renderable(visible) {}

Item::Item(std::initializer_list<Vertex>&& vertices, bool visible) :
    Renderable(visible),
    __vertices(std::forward<std::initializer_list<Vertex>>(vertices)) {}

void Item::setColor(Color color) {
  __color = color;
}

void Item::render() {
  
  glPushMatrix();
  
  glMultMatrixf(__transform);
  glColor4f(__color.fr(), __color.fg(), __color.fb(), __color.fa());
  
  glVertexPointer(4, GL_FLOAT, 0, &__vertices[0]);
  glDrawArrays(GL_TRIANGLES, 0, __vertices.size());
  
  glPopMatrix();
}

} /* namespace Dee */
