#ifndef CIRCLE_H
#define CIRCLE_H

#include "figure.h"

class Circle : public Figure {
public:
    Circle();  // Añadiendo constructor
    ~Circle(); // Añadiendo destructor

    virtual void draw() const override;
};

#endif
