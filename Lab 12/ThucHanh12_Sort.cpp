//! @Filename ThucHanh12_Sort.cpp
//! @Author LocVU
//! @Creaton 26.11.15

#include <iostream>
#include <fstream>
using namespace std;

void swap(int&a,int&b){
    int c;
    c = a;
    a = b;
    b = c;
}

void bubbleSort(int a[], int n){
    for (int i = 0; i < n ; i++){
        for(int j = 0; j < n-1; j++){
            if ( a[j] < a[j+1]){
                swap(a[j], a[j+1]);
            }
        }
    }
}

void insertSort(int a[], int n){
    int key, j;
    for(int i = 1; i < n; i++){
        key = a[i];
        j = i - 1;
        while ( j >= 0 &&  key > a[j]){
            a[j+1] = a[j];
            j -= 1;
        }
        a[j+1] = key;
    }
}

void selectionSort(int a[], int n){
    int max;
    for(int i = 0; i < n-1; i++){
        max = i;
        for(int j = i+1; j < n; j++){
            if(a[j] > a[max]){
                max = j;
            }
        }
        if(max != i){
            swap(a[max], a[i]);
        }
    }
}

void print(int a[], int n){
    for (int i = 0 ; i < n ; i++){
        cout << a[i] << " ";
    }
}

int main(){
    int a[6] = {3,6,5,2,1};
    int n = 5;
    selectionSort(a, n);
//    insertSort(a, n);
//    bubbleSort(a, n);
    print(a, n);
    return 0;
}
