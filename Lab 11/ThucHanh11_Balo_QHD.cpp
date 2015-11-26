//! @Filename ThucHanh11_Balo_QHD.cpp
//! @Author LocVU
//! @Creaton 26.11.15

#include <iostream>

using namespace std;

int main(){
    int f[MAX][MAX];
    int w[MAX];         // trong luong vat
    float v[MAX];       // gia tri vat
    int n; //So do vat
    int kl; //Khoi luong balo
    cout << "Nhap so luong do vat : ";
    cin >> n ;
    cout << "Khoi luong balo chua toi da : ";
    cin >> kl;
    cout << "Nhap trong luong va gia tri cua tung do vat: ";
    for (int i=1;i<=n;i++){
        cout << "Khoi luong vat " << i << " : ";
        cin >> w[i];
        cout << "Gia tri cua vat " << i << " : ";
        cin >> v[i];
    }

    for (int i=1; i<=kl; i++){
        f[0][i] = 0;
    }

    for (int i=1; i<=n; i++){
        for (int j=0; j<=kl; j++){
            f[i][j] = f[i-1][j];
            if (w[i] <= j && f[i][j] < v[i] + f[i-1][j-w[i]] ) {
                f[i][j] = v[i] + f[i-1][j-w[i]];
            }
        }
    }

    cout<< "Gia tri lon nhat cua balo la: " <<f[n][kl]<<endl;//ket qua
    return 0;
}
