#ifndef __BITS_H__
#define __BITS_H__
#include <iostream>
#include <cstddef> // size_t
using namespace std;

using T = unsigned int;

void SwapBits(T &var1, T &var2, size_t pos);
void PrintByBits(ostream &os, T &num);
void BitsDemo();
void BitsPlayground();
#endif
