//! @Filename TH2_radixSort.cpp
//! @Creaton 2.12.15
//! @Source Internet
#include <iostream>
#include <string.h>
#include <stdlib.h>
using namespace std;
const int MAX=25;

void radix(int byte, int N, int * source, int * dest);
void radixSort (int *source, int *temp, int N);
void setup(int arr[], int n);
void print(int arr[], int n);

int main(){
    int n;
    srand(time(0));
    n = rand() % (MAX-2) + 2;
    int arr[MAX];
    int temp[n];
    cout << "Setup: " << endl;
    setup(arr, n);
    print(arr, n);

    radixSort(arr, temp, n);
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

void radix(int byte, int N, int * source, int * dest){
    int count[256];
    int index[256];
    memset(count , 0 , sizeof (count));
    for ( int i=0; i<N; i++ )
		count[((source[i])>>(byte*8))&0xff]++;

	index[0]=0;
	for (int i=1; i<256; i++ )
		index[i] = index[i-1] + count[i-1];
	for (int i=0; i<N; i++ )
		dest[index[((source[i])>>(byte*8))&0xff]++] = source[i];
}

void radixSort (int *source, int *temp, int N){
	radix (0, N, source, temp);
	radix (1, N, temp, source);
	radix (2, N, source, temp);
	radix (3, N, temp, source);
}
