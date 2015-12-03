//! @Filename TH2_quickSort.cpp
//! @Creaton 2.12.15

#include <iostream>
#include <stdlib.h>
using namespace std;
const int MAX=25;

void swap(int&a,int&b);
void print(int arr[], int n);
void setup(int arr[], int n);
void partition(int arr[], int a, int b, int &k);
void quickSort(int arr[], int a, int b);

int main(){
    int n;
    srand(time(0));
    n = rand() % (MAX-2) + 2;
    int arr[MAX];
    cout << "Setup: " << endl;
    setup(arr, n);
    print(arr, n);

    quickSort(arr, 0, n-1);
    cout << "Sort : " << endl;
    print(arr, n);
    return 0;
}

void swap(int&a,int&b){
    int c;
    c = a;
    a = b;
    b = c;
}

void print(int arr[], int n){
    for(int i=0; i < n ; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}

void setup(int arr[], int n){
    for(int i=0; i < n ; i++){
        arr[i] = rand() % 100;
    }
}

void partition(int arr[], int a, int b, int &k){
    int pivot = arr[a];
    int left = a+1, right = b;
    do{
        while(left <= right && arr[left] <= pivot){
            left++;
        }
        while(left <= right && arr[right] > pivot){
            right--;
        }
        if(left < right){
            swap(arr[left], arr[right]);
            left++;
            right--;
        }
    }while(left <= right);
    swap(arr[a], arr[right]);
    k = right;
}

void quickSort(int arr[], int a, int b){
    if(a < b){
        int k = int((a+b)/2);
        partition(arr, a, b, k);
        if (a <= k-1){
            quickSort(arr, a, k-1);
        }
        if (k+1 <= b){
            quickSort(arr, k+1, b);
        }
    }
}
