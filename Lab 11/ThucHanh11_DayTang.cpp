//! @Filename ThucHanh11_DayTang.cpp
//! @Author LocVU
//! @Creaton 24.11.15

#include <iostream>
#include <fstream>
#include <limits.h>
using namespace std;
const int MAX_SIZE = 100;

ifstream is("input.txt");

void input(int n, int a[]){
    for(int i = 0; i < n; i++){
        is >> a[i+1];
    }
}

// Duyet day tu cuoi
void output(int n, int a[]){
    int i, j, jmax, L[n+2], T[n+2];
    // L[i] la mang chieu dai mang giam dan tai vi tri i
    // T[i] la mang chua dia chi cua phan tu tiep theo
    // jmax la vi tri co chieu dai cuc dai
    a[0] = INT_MIN;
    a[n+1] = INT_MAX;
     L[n+1]=1;

     for(i=n ; i>=0 ; i--){
          jmax = n+1;
          // Xac dinh jmax
          for( j=i+1 ; j<=n+1 ; j++){
               if(a[j] > a[i] && L[j] > L[jmax]){
                    jmax = j;
               }
               L[i] = L[jmax]+1;
               T[i] = jmax;
          }
     }
     i=T[0];
     cout << L[0]-2 << endl;   // Tru 2 phan tu INT_MIN va INT_MAX
     while( i != n+1 ){
                  cout << "a[" << i << "]=" << a[i] << "\t" << endl;
                  i = T[i];
     }
}

int main(){
    int n, a[MAX_SIZE];
    is >> n;
    input(n, a);
    output(n, a);
    return 0;
}
