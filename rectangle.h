#ifndef RECTANGLE_H
#define RECTANGLE_H

#include <iostream>
#include <string>

using namespace std;

class Rectangle {
public:
    Rectangle(string _name);
    virtual ~Rectangle();
    virtual void draw();

private:
    string name;
};

#endif
