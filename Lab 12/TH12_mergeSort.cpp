//! @Filename TH2_mergeSort.cpp
//! @Creaton 2.12.15

#include <iostream>
#include <stdlib.h>
using namespace std;
const int MAX=25;

void print(int arr[], int n);
void setup(int arr[], int n);
void merge(int arr[], int left, int mid, int right);
void mergeSort(int arr[], int left, int right);

int main(){
    int n;
    srand(time(0));
    n = rand() % (MAX-2) + 2;
    int arr[MAX];
    cout << "Setup: " << endl;
    setup(arr, n);
    print(arr, n);

    mergeSort(arr, 0, n-1);
    cout << "Sort : " << endl;
    print(arr, n);
    return 0;
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
void merge(int arr[], int left, int mid, int right){
    int findex1 = left, findex2 = mid + 1;
    int lindex1 = mid, lindex2 = right;
    int index = left, temp[right];
    while( findex1 <= lindex1 && findex2 <= lindex2){
        if( arr[findex2] > arr[findex1]){
            temp[index] = arr[findex1];
            index++;
            findex1++;
        }else{
            temp[index] = arr[findex2];
            index++;
            findex2++;
        }
    }
    if( findex2 > lindex2){
        while( findex1 <= lindex1){
            temp[index] = arr[findex1];
            index++;
            findex1++;
        }
    }
    if( findex1 > lindex1){
        while( findex2 <= lindex2){
            temp[index] = arr[findex2];
            index++;
            findex2++;
        }
    }

    for(index = left; index <= right; index++){
        arr[index] = temp[index];
    }
}

void mergeSort(int arr[], int left, int right){
    if(left < right){
        int mid = int((left+right)/2);
        mergeSort(arr, left, mid);
        mergeSort(arr, mid+1, right);
        merge(arr, left, mid, right);
    }

}
