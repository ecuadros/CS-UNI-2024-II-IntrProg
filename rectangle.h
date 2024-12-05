#ifndef _RECTANGLE_H_
#define _RECTANGLE_H_
#include "figure.h"

class Rectangle : public Figure {
public:
    virtual void draw() const override;
};
#endif
