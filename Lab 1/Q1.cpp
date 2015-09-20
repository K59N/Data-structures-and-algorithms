#include "iostream"
using namespace std;

int main(){
	int m = 3, n = 4;
	int** a;
	a = new int*[m];   //do la mang dong nen phai cap bo nho cho no
	for (int i = 0; i < m; i++)
		a[i] = new int[n];
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
			cin >> a[i][j];
    for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
			cout << a[i][j];
	return 0;
}
