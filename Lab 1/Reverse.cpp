/* Filename : Reverse.cpp
 * Author : Loc VU
 * Date : 7, Sep, 2015
 */
//! \brief read to DAYSO2.txt
//!     @ write to KETQUA1.txt: reverse of DAYSO2.txt

#include <iostream>
#include <fstream>
const  int MAX=200;
using namespace std;

int main(){
    ifstream is("DAYSO2.txt");
    ofstream os("KETQUA1.txt");
    int a[MAX];
    int i = -1;

    while(!is.eof()){
        i++;
        is >> a[i];
    }

    for ( i ; i > 0 ; i--){
        os << a[i-1] << endl;
    }

    is.close();
    os.close();
    return 0;
}

