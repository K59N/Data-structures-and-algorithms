/* Filename : CutK.cpp
 * Author : Loc VU
 * Date : 7, Sep, 2015
 */
//! \brief read to DAYSO2.txt
//!     @ write to KETQUA2.txt: n-k(th) num to nth num, then write 1-k(th) num <num in each line>

#include <iostream>
#include <fstream>
const  int MAX=200;
using namespace std;

int main(){
    ifstream is("DAYSO2.txt");
    ofstream os("KETQUA2.txt");
    int a[MAX];
    int i = -1;

    while(!is.eof()){
        i++;
        is >> a[i];
    }
    int n;
    n = i;
    cout << "Enter a number: k = " ;
    int k;
    cin >> k;
    if(k>0 && k <= n){
        for (int j = k; j < n ; j++){
            os << a[j] << endl;
        }
        for (int j = 0; j < k ; j++){
            os << a[j] << endl;
        }
    }

    is.close();
    os.close();
    return 0;
}
