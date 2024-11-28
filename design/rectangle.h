#ifndef __RECTANGLE_H__
#define __RECTANGLE_H__

#include "figure.h"

class Rectangle : public Figure
{
public:
    // TODO: crear el constructor del Rectangle
            Rectangle(string _name);
    virtual ~Rectangle();   
    virtual void draw();
};

#endif