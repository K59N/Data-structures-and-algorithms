//! \Filename: TH13_mergeSort.cpp
//! \Author: LocVU
//! \Date: 7.12.2015

#include <iostream>
#define FORI(pos, first, last) \
    for(int pos = ((int)(first)); pos < ((int)(last)); pos++)

using namespace std;

void swap(int&a,int&b);
void merge(int arr[], int left, int mid, int right, int index[]);
void mergeSort(int arr[], int left, int right, int index[]);
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
    mergeSort(a, 0, n-1, index);
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

void merge(int arr[], int left, int mid, int right, int index[]){
    int findex1 = left, findex2 = mid + 1;
    int lindex1 = mid, lindex2 = right;
    int i = left, temp[right], temp2[right];
    while( findex1 <= lindex1 && findex2 <= lindex2){
        if( arr[findex2] > arr[findex1]){
            temp[i] = arr[findex1];
            temp2[i] = findex1;
            i++;
            findex1++;
        }else{
            temp[i] = arr[findex2];
            temp2[i] = findex2;
            i++;
            findex2++;
        }
    }
    if( findex2 > lindex2){
        while( findex1 <= lindex1){
            temp[i] = arr[findex1];
            temp2[i] = findex1;
            i++;
            findex1++;
        }
    }
    if( findex1 > lindex1){
        while( findex2 <= lindex2){
            temp[i] = arr[findex2];
            temp2[i] = findex2;
            i++;
            findex2++;
        }
    }

    for(i = left; i <= right; i++){
        arr[i] = temp[i];
        index[i] = temp2[i];
    }
}

void mergeSort(int arr[], int left, int right, int index[]){
    if(left < right){
        int mid = int((left+right)/2);
        mergeSort(arr, left, mid, index);
        mergeSort(arr, mid+1, right, index);
        merge(arr, left, mid, right, index);
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
