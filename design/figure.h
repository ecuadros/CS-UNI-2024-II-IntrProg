#ifndef __FIGURE__H__
#define __FIGURE__H__
#include <string>
using namespace std;

class Figure{
private:
    string m_name;
public:
    Figure(const string &_name= "");
    virtual ~Figure();

    virtual void draw();

public:
    void SetName(const string _name);
    string GetName() const;
};

#endif