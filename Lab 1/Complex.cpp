/* Filename : Complex.cpp
 * Author : Loc VU
 * Date : 7, Sep, 2015
 */
//! \brief define class Complex
//!     @ operator : add, sub, mul 2 complex number

#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;
class Complex{
    public:
        Complex(float, float);
        Complex(const Complex &);
        Complex operator +(Complex);
        Complex operator -(Complex);
        Complex operator *(Complex);
        void operator= (Complex);
        friend ostream& operator << (ostream &s, Complex &c);
    private:
        int realPart, imagPart;
};

Complex::Complex(float real=0.0f, float imag=0.0f){
    realPart = real;
    imagPart = imag;
}
Complex::Complex(const Complex &c){
    this->realPart = c.realPart;
    this->imagPart = c.imagPart;
}

void Complex::operator=(Complex c){
    this->realPart = c.realPart;
    this->imagPart = c.imagPart;
}

Complex Complex::operator+ (Complex c){
    Complex temp;
    temp.realPart = this->realPart + c.realPart;
    temp.imagPart = this->imagPart + c.imagPart;
    return temp;
}
Complex Complex::operator-(Complex c){
    Complex temp;
    temp.realPart = this->realPart - c.realPart;
    temp.imagPart = this->imagPart - c.imagPart;
    return temp;
}
Complex Complex::operator*(Complex c){
    Complex temp;
    temp.realPart = this->realPart*c.realPart - this->imagPart*c.imagPart ;
    temp.imagPart = this->realPart*c.imagPart + this->imagPart*c.realPart;
    return temp;
}

ostream& operator << (ostream &s, Complex &c){
 //  s << "Real Part : " << c.realPart << endl;
 //   s << "Imagi Part: " << c.imagPart << endl;
    s << "= " << c.realPart << setiosflags(ios::showpos) << c.imagPart << "i" << endl << resetiosflags(ios::showpos);
    return s;
}
int main(){
    Complex a(10.0 , -2.0), b(-2);
    cout << "a "  << a << endl;
    cout << "b "  << b << endl;
    Complex d,e,f;
    d = a+b;
    e = a-b;
    f = a*b;
    cout << "Add" << endl;
    cout << "d "  << d << endl;
    cout << "Sub" << endl;
    cout << "e "  << e << endl;
    cout << "Mul" << endl;
    cout << "f "  << f << endl;
    return 0;
}
