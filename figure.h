#ifndef _FIGURE_H_
#define _FIGURE_H_
#include <iostream>

class Figure {
public:
    virtual void draw() const = 0;
    virtual ~Figure() = default;
};
#endif
