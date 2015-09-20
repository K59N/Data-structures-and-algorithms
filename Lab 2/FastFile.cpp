//! \Filename: FastFile.cpp
//! \Author: Loc VU
//! \Date: 17.Sep.15

//! \brief : Have a array A NxN consist of numbers: 1 and 0 (1 before 0)
//!         - Find row with the most no.1 in array A ( time complexity : O(n) )

#include <iostream>
#include  <cstdlib>
using namespace std;

int findLine(int arr[][200], int N);
int main(){
    int N;
    cout << "Enter the array's size N = " ;
    cin >> N;
    int arr[N][200];
    cout << "Enter array's values (0 or 1)" << endl;
    for (int i=0; i < N; i++){
        cout << "Row " << i+1 << endl;
        for (int j=0; j < N; j++){
            cin >> arr[i][j];
            if (arr[i][j] != 0 && arr[i][j] != 1 ){
                exit(0);
            }
        }
    }
    cout << "The row with the most no.1 is : " << findLine(arr, N);

    return 0;
}
int findLine(int arr[][200], int N){
    int result = 0;
    int i = 0, j = 0;
    while(i < N){
        if (arr[i][j] == 1){
            j++;
            if(arr[i][j] == 0){
                result = i;
                i++;
            }
        }else
            i++;
    }
    return result + 1;
}
