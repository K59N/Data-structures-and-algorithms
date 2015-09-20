/* Filename : GenNum.cpp
 * Author : Loc VU
 * Date : 7, Sep, 2015
 */
//! \brief read to DAYSO1.txt
//!     @ print last number
//!     @ print the second largest
//!     @ print k int-num largest with k entered from keyboard

#include <iostream>
#include <fstream>

using namespace std;

int main(){
    ifstream is("DAYSO1.txt");
    int n, temp, k;
    is >> n;
    int a[n];

    cout << n << endl;
    for (int i=0; i < n; i++){
        is >> a[i];
        cout << a[i] << endl;
    }
    cout << "The last number : " << a[n-1];
    //sort
    for (int i=0 ; i < n-1 ; i++)
        for (int j = i ; j < n ; j++){
            if (a[i] > a[j]){
                temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
    cout << "The second largest is " << a[n-2] << endl;
    cout << "How many numbers are you want to enter?" ;
    cin >> k;
    cout << k << " number lasget: " << endl;
    for (int i = n-1 ; i > n-k-1 ; i--){
        cout << a[i] << " ";
    }
    is.close();
    return 0;
}

