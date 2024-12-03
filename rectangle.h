#ifndef _RECTANGLE_H_
#define _RECTANGLE_H_

#include "figure.h"

class Rectangle : public Figure {
public:
    Rectangle();  // Añadiendo constructor
    ~Rectangle(); // Añadiendo destructor

    virtual void draw() const override;
};

#endif
