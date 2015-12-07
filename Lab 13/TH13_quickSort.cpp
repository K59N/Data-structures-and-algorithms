//! \Filename: TH13_quickSort.cpp
//! \Author: LocVU
//! \Date: 7.12.2015

#include <iostream>
#define FORI(pos, first, last) \
    for(int pos = ((int)(first)); pos < ((int)(last)); pos++)

using namespace std;

void swap(int&a,int&b);
void partition(int arr[], int a, int b, int &k, int index[]);
void quickSort(int arr[], int a, int b, int index[]);
void print(int a[], int n);
void check(int a[], int n, int index[]);

int main(){
    int a[7] = {3,9,6,4,3,2,1};
    int n =  sizeof(a) / sizeof(a[0]);
    int index[n];
    FORI(i, 0 , n)
        index[i] = i;

    cout << "Array: ";
    print(a, n);
    cout << "\nIndex: " ;
    print(index, n);
    cout << "\n=============================" << endl;
    quickSort(a, 0, n-1, index);
    cout << "\nSort : " ;
    print(a,n);
    cout << "\nIndex: " ;
    print(index, n);

    check(a, n , index);
    return 0;
}

void print(int a[], int n){
    FORI(i, 0, n)
        cout << a[i] << " " ;
}

void swap(int&a,int&b){
    int c;
    c = a;
    a = b;
    b = c;
}

void partition(int arr[], int a, int b, int &k, int index[]){
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
            swap(index[left], index[right]);
            left++;
            right--;
        }
    }while(left <= right);
    swap(arr[a], arr[right]);
    swap(index[a], index[right]);
    k = right;
}

void quickSort(int arr[], int a, int b, int index[]){
    if(a < b){
        int k = int((a+b)/2);
        partition(arr, a, b, k, index);
        if (a <= k-1){
            quickSort(arr, a, k-1, index);
        }
        if (k+1 <= b){
            quickSort(arr, k+1, b, index);
        }
    }
}


void check(int a[], int n, int index[]){
    FORI(i, 0, n-1){
        FORI(j, i+1, n){
            if(a[i] == a[j]){
                if(index[i] < index[j])
                    cout << "\nThuat toan on dinh" << endl;
                else
                    cout << "\nThuat toan ko on dinh" << endl;
            }
        }
    }
}
