//! @author: Loc VU
//! Created on 24.Sep.15

//! \brief : Complete source code in this file

#include <iostream>
#include <cstdlib>
#include <assert.h>
#include <fstream>
//#include <conio.h>
using namespace std;

class ArrayList{
public:
    static const int MAX_SIZE = 100; // So phan tu toi da cua mang
    ArrayList(); // Khoi tao danh sach rong
    ArrayList(int a[], int n); // Khoi tao DS bang du lieu luu trong mang a
    ArrayList(const char * filename); // Khoi tao DS bang du lieu luu trong tep filename

    bool empty() const; // Kiem tra DS rong hay khong
    int length() const; // Xac dinh do dai DS
    void insert(const int x, int i); // Xen gia tri x vao vi tri i trong DS
    void append(const int x); // Them x vao duoi DS
    void erase(int i); // Loai khoi DS phan tu o vi tri i
    int& at(int i); // Tra ve tham chieu toi phan tu o vi tri i
    void print() const; // In ra man hinh toan bo DS
private:
    int element[MAX_SIZE]; // Mang tinh element luu toan bo DS
    int last; // chi so cua phan tu cuoi cung
};

ArrayList::ArrayList(){
    last = -1;
}

ArrayList::ArrayList(int a[], int n){
    for(int i = 0; i < n ; i++){
        element[i] = a[i];
        last = n-1;
    }
}

ArrayList::ArrayList(const char * filename){
	int i=0;
	ifstream is;
	is.open(filename);
	while (!is.eof())
	{
		is >> element[i];
		i++;
		if (i == MAX_SIZE+1) break;
	}
	is.close();
	last = i-2;
}
bool ArrayList::empty() const{
    if (last < 0)
        return true;
}

int ArrayList::length() const{

    return last+1;
}

void ArrayList::insert(const int x, int i){
    assert(last < MAX_SIZE - 1 && i <= last);
    last++;
    element[last] = x;
    int temp;
    for (int j = last; j > i ; j--){
        temp = element[j];
        element[j] = element[j-1];
        element[j-1] = temp;
    }

}

void ArrayList::append(const int x){
    assert(last < MAX_SIZE - 1);
    last++;
    element[last] = x;
}

void ArrayList::erase(int i){
    assert(last >= 0 && i <= last && i >= 0);
    last--;
    for(int j = i; j < last; j++){
        element[j+1] = element[j];
    }
}

int& ArrayList::at(int i){
    assert(last >= 0 && i <= last && i >= 0);
    return element[i];
    //return i;
}

void ArrayList::print() const{
    for (int i = 0; i <= last; i++){
        cout << element[i] << " ";
    }
    cout <<"Last: " << last<< endl;
}

int main(){
    cout << "Chuong trinh test KDLTT danh sach so nguyen" << endl;
    cout << "Tac gia: [Loc VU]\n--------------------" << endl;

    cout << "L1: L1.append(3);L1.append(4);L1.append(5);"
        << "L1.insert(2, 0); L1.insert(1, 0); L1.insert(3, 2);" << endl;

    ArrayList L1; L1.print(); cout << endl;
    L1.append(3); L1.print(); cout << endl;
    L1.append(4); L1.print(); cout << endl;
    L1.append(5); L1.print(); cout << endl;

    L1.insert(2, 0); L1.print(); cout << endl;
    L1.insert(1, 0); L1.print(); cout << endl;
    L1.insert(3, 2); L1.print(); cout << endl;

    cout << "\nL2: L2.append(4);L2.append(4);L2.append(1);"
        << "L2.erase(2); L2.insert(5, 1); L2.insert(3, 2);" << endl;

    ArrayList L2;
    L2.append(4);
    L2.append(4);
    L2.append(1);
    L2.print();

    L2.erase(2);
    L2.print();

    L2.insert(5, 1);
    L2.insert(3, 2);
    L2.print();
    cout <<  "L2.at(3): " << L2.at(3) << endl;
    L2.print();
    cout << endl;

    cout << "\nL3: input.txt" << endl;
    ArrayList L3("input.txt");
    L3.print();

//    getch();
    return 0;
}
