#ifndef __RECTANGLE_H__
#define __RECTANGLE_H__

#include "figure.h"

class Rectangle : public Figure
{
public:
    Rectangle(string _name);
    virtual ~Rectangle();
    
    // TODO: crear el constructor del Rectangle
    virtual void draw();
};

#endif