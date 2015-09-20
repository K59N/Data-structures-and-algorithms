//! \Filename: Power.cpp
//! \Author: Loc VU
//! \Date: 17.Sep.15

//! \brief : Compute power of x^n with computational complexity : O(logn)
#include <iostream>
using namespace std;

double power(double, unsigned int);

int main(){
    double x;
    unsigned int n;
    cin >> x >> n;
    cout << "Result: " << power(x,n);
    return 0;
}

double power(double x, unsigned int n){
    if (n == 0) return 1;
    else {
        double y = power(x , n/2);
        if (n % 2 == 0) return y*y;
        else return x*y*y;
    }
}
