#include "simphys/vec3.h"

#ifndef MAT33_H
#define MAT33_H

namespace simphys{
class mat33
{
private:
    float data[3][3];
    
public:
    //constructor
    mat33();
    
    //parameterized constructor
    mat33(float a1, float a2, float a3, float b1, float b2, float b3, float c1, float c2, float c3);
    
    //transpose
    void transpose();
    
    //print matrix
    void printAll();
    
    //Overloaded function call operator
    float& operator()(int i, int j);
    
    //Friend non-member overloads
    friend mat33 operator*( mat33& left, mat33& right);
    friend simphys::vec3 operator*( mat33& left, simphys::vec3& right);
};

}

#endif
