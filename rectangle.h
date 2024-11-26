#ifndef __RECTANGLE_H__
#define __RECTANGLE_H__
#include "figure.h"

class Rectangle: publicFigure 
{public:
  virtual void draw();
};
void draw() // Referenciado por "::draw()" en rectangle.cpp
#endif
