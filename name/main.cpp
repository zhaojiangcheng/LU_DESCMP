#include<iomanip>
#include<iostream>
#include<array>
#include<cassert>
#include "descmp.h"
using namespace std;
using multiarr = array<array<double,length>,width>;
//the const in the global scope means that it can be linked externally.就是外部连接；英文实在打不出来了。

int main(int argc, char const *argv[])
{
    multiarr arr = {2, 3, 0, 0,
                    3, 2, 3, 0,
                    0, 3, 2, 3,
                    0, 0, 3, 2};
    //target matrix
    multiarr brr = {0};
    multiarr crr = {0};
    print_matrix(arr, length);
    LU_descomposed(arr, brr, crr);
    print_matrix(brr, length);
    print_matrix(crr, length);


    //copy(begin(a),end(b),begin(b));
    return 0;

}
/*
 * the LU_descompsed methed is used for chasing method like the followings:
 * a00 a01
 * a10 a11 a12
 *     a21 a22 a23
 *         a32 a33 a34
 *             ........
 *                ........
 *                  an-1n-1 ann
 */
void LU_descomposed(multiarr &a, multiarr &l, multiarr &u)
{

    u[0][0] = a[0][0]; u[0][1] = a[0][1]; l[0][0] = 1;
    for (int i = 1; i < length ; ++i)
    {
        l[i][i] = 1;
        if(i != length -1)
            u[i][i+1] = a[i][i+1];
        l[i][i-1] = a[i][i-1]/u[i-1][i-1];
        u[i][i] = a[i][i] - l[i][i-1]*u[i-1][i];//LU_descomposed matrix;
    }

}//used for computation.

void print_matrix(multiarr a, const int length = ::length)
{
    cout.precision(5);
    cout.setf(ios::left);
    for (int i = 0; i < length ; ++i) {
        for (int j = 0; j < length; ++j) {
            cout << setw(8) << a[i][j];
        }
        cout << endl;
    }
    cout << endl;
}
