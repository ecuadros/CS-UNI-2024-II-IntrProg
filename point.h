#ifndef _POINT_H_
#define _POINT_H_
#include "figure.h"

class Point : public Figure {
public:
    virtual void draw() const override;
};
#endif
