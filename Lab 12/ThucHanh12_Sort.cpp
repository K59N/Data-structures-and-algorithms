//! @Filename ThucHanh12_Sort.cpp
//! @Author LocVU
//! @Creaton 26.11.15

#include <iostream>
#include <fstream>
#include <stdlib.h>
using namespace std;

void swap(int&a,int&b);
void setup(int a[][10], int m, int n);
void bubbleSort(int a[][10], int m, int n);
void insertSort(int a[][10], int m, int n);
void selectionSort(int a[][10], int m, int n);
void print(int a[][10], int m, int n);

int main(){
    int m, n;
    srand(time(0));
    m = rand() % 8 + 2;    // SO PHAN TU CUA DAY SO
    n = rand() % 8 + 2;     // SO DAY SO
    int a[10][10];
    setup(a, m, n);
    cout << "Setup :" << endl;
    print(a, m, n);
    cout << "\nSorted: "<< endl;
   // selectionSort(a, m, n);
    insertSort(a, m, n);
 //   bubbleSort(a, m, n);


    return 0;
}

void swap(int&a,int&b){
    int c;
    c = a;
    a = b;
    b = c;
}

void setup(int a[][10], int m, int n){
    ofstream os("Ndayso.txt");
    os << n << " " << m << endl;

    for(int i = 0; i < n ; i++){
        for(int j=0; j < m; j++){
            a[i][j] = rand() % 100;
            if(a[i][j]  < 10){
                os << " " << a[i][j] << " ";
            }
            else{
                os << a[i][j] << " ";
            }
        }
        os << endl;
    }
    os.close();
}

void bubbleSort(int a[][10], int m, int n){
    int cmp[n], swp[n];
    for (int i = 0; i < n ; i++){
        cmp[i] = 0;
        swp[i] = 0;
        for (int j = 0; j < m ; j++){
            for(int k = 0; k < m-1; k++){
                cmp[i]++;
                if ( a[i][k] < a[i][k+1]){
                    swap(a[i][k], a[i][k+1]);
                    swp[i]++;
                }
            }
        }
    }

    int sumCmp= 0, sumSwp = 0;
    // Tong so lan so sanh va doi cho cua cac hang
    for (int i = 0; i < n ; i++){
        sumCmp += cmp[i];
        sumSwp += swp[i];
    }
    print(a, m, n);
    cout << "Compare: " << (float)sumCmp/n << endl<< "Swap: " << (float)sumSwp/n << endl;
}

void insertSort(int a[][10], int m, int n){
    int cmp[n], swp[n];
    for(int i = 0 ; i < n; i++){
        cmp[i] = 0;
        swp[i] = 0;
        for(int j = 1; j < m; j++){
            for(int k = j; k > 0; k--){
                cmp[i]++;
                if (a[i][k] > a[i][k-1]){
                    swap(a[i][k-1], a[i][k]);
                    swp[i]++;
                }
            }
        }
    }
    int sumCmp= 0, sumSwp = 0;
    // Tong so lan so sanh va doi cho cua cac hang
    for (int i = 0; i < n ; i++){
        sumCmp += cmp[i];
        sumSwp += swp[i];
    }
    print(a, m, n);
    cout << "Compare: " << (float)sumCmp/n << endl<< "Swap: " << (float)sumSwp/n << endl;

}

void selectionSort(int a[][10], int m, int n){
    int max, cmp[n], swp[n];
    for(int i = 0; i < n; i++){
        cmp[i] = 0;
        swp[i] = 0;
        for(int j = 0; j < m-1; j++){
            max = j;
            for(int k = j+1; k < m; k++){
                cmp[i]++;
                if(a[i][k] > a[i][max]){
                    max = k;
                }
            }
            if(max != j){
                swap(a[i][max], a[i][j]);
                swp[i]++;
            }
        }
    }
    int sumCmp= 0, sumSwp = 0;
    // Tong so lan so sanh va doi cho cua cac hang
    for (int i = 0; i < n ; i++){
        sumCmp += cmp[i];
        sumSwp += swp[i];
    }
    print(a, m, n);
    cout << "Compare: " << (float)sumCmp/n << endl<< "Swap: " << (float)sumSwp/n << endl;
}

void print(int a[][10], int m, int n){
    for (int i = 0 ; i < n ; i++){
        for (int j = 0; j  < m ; j++){
            if(a[i][j]  < 10){
                cout << " " << a[i][j] << " ";
            }
            else{
                cout << a[i][j] << " ";
            }
        }
        cout << endl;
    }
}

