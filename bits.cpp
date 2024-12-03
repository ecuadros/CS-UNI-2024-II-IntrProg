#include <string>
#include <fstream>
#include "bits.h"
using namespace std;

void SwapBits(T &var1, T &var2, size_t pos){
    T bit = (1 << pos);
    if( (var1 & bit) != (var2 & bit) ){
        if( var1 & bit ){
            var1 &= ~bit;  
            var2 |= bit;
        }
        else{
            var1 |= bit;
            var2 &= ~bit;
        }
    }
}

void PrintByBits(ostream &os, string msg, T &num){
    auto nbits = sizeof(T) << 3; 
    os << msg;
    for(auto i = nbits ; i > 0 ; --i){
        T bit = 1 << (i-1);
        os << ((num & bit)? 1 : 0);
    }
    os <<endl;
}

void BitsDemo(){
    T var1 = 310,    // 00000100110110
      var2 = 193;
    cout << var1 << endl;
    PrintByBits(cout, "var1=", var1);
    PrintByBits(cout, "var2=", var2);
    SwapBits(var1, var2, 4);
    PrintByBits(cout, "var1=", var1);
    PrintByBits(cout, "var2=", var2);

    ofstream of("ICC-Sunday.txt");
    PrintByBits(of, "var1=", var1);
}

void BitsPlayground(){
    T num1 = 29;     //            00011101   10000000 -128
                     //                       01111111  127
    T num2 = 91;     //            01011011
    T bit1 = 4;      //            00000100
    T rpta = 0;
    if( num1 & bit1 )  //          00000100
    {   cout << "Bit prendido ..." << endl; }
    else
    {   cout << "Bit apagado ..." << endl; }

    rpta = num2 | bit1;         // Prender un bit
    cout << rpta <<endl;

    T bit_neg = ~bit1;        // Invierte los 1 por 0 y los 0 por 1
                              // 11111011
    cout << bit_neg << endl;

    bit1 = 11;                // 00001011
    T num3 = bit1 << 2;       // 00001011 << 2 = 00101100 -> 44
    cout << num3 << endl;
    T num4 = num3 >> 3;       // 00010000 >> 3 = 00000010 ->  5
    cout << num4 << endl;

    T x = 10;
    x += 3; // x = x + 3;
    x -= 3; // x = x - 3;
    x *= 3; // x = x * 3;
    x /= 3; // x = x / 3;

    x &= bit1;  // x = x & bit1 AND
    x |= bit1;  // x = x | bit1 OR
    x ^= bit1;  // x = x ^ bit1 XOR
    x <<= 2;    // x = x << 2;  Shift left
    x >>= 3;    // x = x << 3;  Shift right
}