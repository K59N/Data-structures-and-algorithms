//! @Filename TH2_binSort.cpp
//! @Creaton 2.12.15
//! @Source Internet
#include <iostream>
#include <stdlib.h>
using namespace std;
const int MAX=25;

void binSort(int *a,int n);
void print(int arr[], int n);
void setup(int arr[], int n);

int main(){
    int n;
    srand(time(0));
    n = rand() % (MAX-2) + 2;
    int arr[MAX];
    cout << "Setup: " << endl;
    setup(arr, n);
    print(arr, n);

    binSort(&arr[0], n);
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

void binSort(int *a,int n){
    int i, b[n], max=0, exp=1;
    for (i=0; i<n; i++)
        if (a[i]>max) max=a[i];
    while (max/exp>0)
    {
        int bucket[10]={0};
        for (i=0; i<n; i++)
			bucket[a[i]/exp%10]++;
        for (i=1; i<10; i++)
            bucket[i]+=bucket[i-1];
        for (i=n-1; i>=0; i--)
            b[--bucket[a[i]/exp%10]]=a[i];
        for (i=0; i<n; i++)
            a[i]=b[i];
        exp*=10;
	}
}
