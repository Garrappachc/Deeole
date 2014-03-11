/*
 * color.cpp
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

#include <map>
#include <utility>

#include "utils/logger.h"

#include "color.h"

namespace Dee {
  
  namespace {
    float i2f(int c) {
      return static_cast<float>(c) / 255.0f;
    }
  }

static const std::map<std::string, Color> ColorMap({
  std::make_pair("black",  Color(0, 0, 0)),
  std::make_pair("white",  Color(255, 255, 255)),
  std::make_pair("red",    Color(255, 0, 0)),
  std::make_pair("green",  Color(0, 255, 0)),
  std::make_pair("blue",   Color(0, 0, 255)),
  std::make_pair("yellow", Color(255, 255, 0))
});

Color::Color() :
    __r(0.0f),
    __g(0.0f),
    __b(0.0f),
    __a(255.0f) {}

Color::Color(int r, int g, int b, int a) :
    __r(i2f(r)),
    __g(i2f(g)),
    __b(i2f(b)),
    __a(i2f(a)) {}

Color::Color(float r, float g, float b, float a) :
    __r(r),
    __g(g),
    __b(b),
    __a(a) {}

Color::Color(const std::string& name) {
  if (ColorMap.count(name) > 0) {
    *this = ColorMap.find(name)->second;
  } else {
    Logger::warning("Color: invalid color name: %s", name);
  }
}

void Color::dumpTo(float* array) const {
  array[0] = __r;
  array[1] = __g;
  array[2] = __b;
  array[3] = __a;
}

} /* namespace Dee */
