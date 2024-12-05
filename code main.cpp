#include "figure.h"
#include "rectangle.h"
#include "circle.h"
#include "point.h"

int main() {
    Figure* figure1 = new Rectangle();
    Figure* figure2 = new Circle();
    Figure* figure3 = new Point();

    figure1->draw();
    figure2->draw();
    figure3->draw();

    delete figure1;
    delete figure2;
    delete figure3;
}
