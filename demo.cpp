#include "figure.h"
#include "rectangle.h"
#include "circle.h"

void f_x(figure *p) {
    p -> draw();
}

void f_y(figure &robj) {
    robj.draw();
}

void demo() {
    figure *pf[2] = {new rectangle, new circle};

    for (int i = 0; i < 2; i++) {
        pf[i] -> draw();
        f_x(pf[i]);
        f_y(*pf[i]);
    }
}