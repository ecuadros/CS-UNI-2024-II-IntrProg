#ifndef __POINT_H__
#define __POINT_H__

#include "figure.h"

class Point : public Figure{
public:
    Point(string _name);
    virtual ~Point();
    virtual void draw();
};

#endif