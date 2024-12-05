#ifndef CIRCLE_H
#define CIRCLE_H

#include <iostream>
#include <string>

using namespace std;

class Circle {
public:
    Circle(string _name);
    virtual ~Circle();
    virtual void draw();

private:
    string name;
};

#endif
