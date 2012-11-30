#include "simphys/mat33.h"
#include "simphys/vec3.h"
#include <iostream>

using namespace simphys;

//constructor
mat33::mat33()
{
    for( int i=0; i<3; i++)
    {
        for( int j=0; j<3; j++ )
        {
            data[i][j] = 0.0f;
        }
    }
}
    
//parameterized constructor
mat33::mat33(float a1, float a2, float a3, float b1, float b2, float b3, float c1, float c2, float c3)
{
    data[0][0] = a1;
    data[0][1] = a2;
    data[0][2] = a3;
    
    data[1][0] = b1;
    data[1][1] = b2;
    data[1][2] = b3;
    
    data[2][0] = c1;
    data[2][1] = c2;
    data[2][2] = c3;
}

//transpose
void mat33::transpose()
{
    float temp[3][3];
    
    //transpose into temp
    for( int i=0; i<3; i++ )
    {
        for( int j=0; j<3; j++ )
        {
            temp[i][j] = data[j][i];
        }
    }
    
    //copy from temp into transpose
    for( int i=0; i<3; i++ )
    {
        for( int j=0; j<3; j++ )
        {
            data[i][j] = temp[i][j];
        }
    }
}

//print matrix
void mat33::printAll()
{
    using namespace std;
    
    //loop over rows
    for( int i=0; i<3; i++)
    {
        //loop over columns
        for( int j=0; j<3; j++ )
        {
            cout << data[i][j] << " ";
        }
        cout << endl;
    }
}

//Overloaded function call operator
float& mat33::operator()(int i, int j)
{
    return data[i][j];
}

//Overloaded * operator (mat22 * mat22)
mat33 simphys::operator*( mat33& left, mat33& right)
{

    mat33 output;
    
    for( int i=0; i < 3; i++ )
    {
        for( int j=0; j<3; j++ )
        {
            for( int k=0; k<3; k++ )
            {
                output(i,j) +=  left(i,k)*right(k,j);
            }
        }
    }
    
    return output;
}

simphys::vec3 simphys::operator*( mat33& left, simphys::vec3& right)
{
    using namespace std;
    simphys::vec3 output;
    
    for( int i=0; i<3; i++ )
    {
        for( int j=0; j<3; j++ )
        {
            switch(i)
            {
                case 0:
                    output.setX( output.getX() + left(i,j)*right.getX() );
                    break;
                case 1:
                    output.setY( output.getY() + left(i,j)*right.getY() );
                    break;
                case 2:
                    output.setZ( output.getZ() + left(i,j)*right.getZ() );
                    break;
                default:
                    break;
            }
        }
    }
    
    return output;
}


