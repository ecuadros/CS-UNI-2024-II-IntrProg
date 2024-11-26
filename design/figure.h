#ifndef __FIGURE__H__
#define __FIGURE__H__
#include <string>
using namespace std;

class Figure{
private:
    string m_name;
public:
    Figure(string name="");
    virtual ~Figure();

    virtual void draw();

public:
    void SetName(string _name);
    string GetName();
};

#endif