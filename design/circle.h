#ifndef __CIRCLE_H__
#define __CIRCLE_H__

#include "figure.h"

class Circle : public Figure
{
public:
    Circle(string _name);
    virtual ~Circle();
    virtual void draw();
};

#endif 