//! \Filename: MaxMin.cpp
//! \Author: Loc VU
//! \Date: 17.Sep.15

//! \brief : find Max, Min of a array have n number.
//!         - Use less than 3n/2 comparisons
#include <iostream>
using namespace std;

void MinMax(int arr[], int n);//Find Max and Min
int main(){
    int n;
    cout << "Enter the number of arrays \n";
    cin >> n;
    int arr[n];
    cout << "Enter array's values \n";
    for (int i = 0; i < n ; i++){
        cout << "array[" << i+1 << "]: ";
        cin >> arr[i];
    }
    MinMax(arr, n);
    return 0;
}

void MinMax(int arr[],int n){
    int Max = arr[0], Min = arr[0], i;
    if (n % 2 == 0) i = 0;
    else i = 1;
    for (i; i < n ; i+=2){
        if (arr[i] >= arr[i+1]){
            if ( arr[i] > Max)
                Max = arr[i];
            if (arr[i+1] < Min)
                Min = arr[i+1];
        }else{
            if ( arr[i+1] > Max)
                Max = arr[i+1];
            if (arr[i] < Min)
                Min = arr[i];
        }
    }
    cout << "Max : " << Max << endl << "Min: " << Min << endl;
}
