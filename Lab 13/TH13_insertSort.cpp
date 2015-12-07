//! \Filename: TH13_insertSort.cpp
//! \Author: LocVU
//! \Date: 7.12.2015

#include <iostream>
#define FORI(pos, first, last) \
    for(int pos = ((int)(first)); pos < ((int)(last)); pos++)
#define FORJ(pos, first, last) \
    for(int pos = ((int)(last)); pos > ((int)(first)); pos--)

using namespace std;

void swap(int&a,int&b);
void insertSort(int a[], int n, int index[]);
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
    insertSort(a, n, index);
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

void insertSort(int a[], int n, int index[]){
    FORI(i, 1 ,n){
        FORJ(j, 0, i){
            if (a[j] > a[j-1]){
                swap(a[j-1], a[j]);
                swap(index[j-1], index[j]);
            }
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
