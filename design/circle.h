#ifndef __CIRCLE_H__
#define __CIRCLE_H__

#include "figure.h"

class Circle : public Figure
{
public:
    Circle(const std::string &name = "Circle");// TODO: crear el constructor del Circle
    virtual void draw();
};

#endif 
