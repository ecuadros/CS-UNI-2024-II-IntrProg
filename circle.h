#ifndef _CIRCLE_H_
#define _CIRCLE_H_
#include "figure.h"

class Circle : public Figure {
public:
    virtual void draw() const override;
};
#endif
