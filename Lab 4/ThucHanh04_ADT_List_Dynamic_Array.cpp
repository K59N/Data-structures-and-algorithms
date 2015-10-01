//! @author: Loc VU
//! Created on 30.Sep.15

//! \brief : Complete source code in this file

#include <iostream>
#include <fstream>
#include <assert.h>


//#include <conio.h>
using namespace std;

class DArrayList{
public:
    DArrayList(); // Khoi tao danh sach rong
    DArrayList(int a[], int n); // Khoi tao DS bang du lieu luu trong mang a
    DArrayList(const char * filename); // Khoi tao DS bang du lieu luu trong tep filename
    DArrayList(const DArrayList & someList); // Ham kien tao sao chep (copy constructor)
    ~DArrayList(); // Ham huy (destructor)

    void operator=(const DArrayList & someList); // Nap chong phep gan
    bool empty() const; // Kiem tra DS rong hay khong
    int length() const; // Xac dinh do dai DS
    void insert(const int x, int i); // Xen gia tri x vao vi tri i trong DS
    void append(const int x); // Them x vao duoi DS
    void erase(int i); // Loai khoi DS phan tu o vi tri i
    int& at(int i); // Tra ve tham chieu toi phan tu o vi tri i
    void print() const; // In ra man hinh toan bo DS
private:
    int * element; // Mang dong element luu toan bo DS
    int last; // chi so cua phan tu cuoi cung
    int size; // kich thuoc (so phan tu toi da) cua mang element
};

DArrayList::DArrayList(){
    last = -1;
    size = 0;
    element = new int[size];
}

DArrayList::~DArrayList(){
    if(element){
        delete [] element;
        element = NULL;
    }
    last = -1;
    size = 0;
}

DArrayList::DArrayList(int a[], int n){
	last=n-1;
	size=n;
	element = new int[size];
	for (int i=0; i<n; i++)
		element[i]=a[i];
}

DArrayList::DArrayList(const char * filename){
    size=0;
    element = new int[size];
	ifstream infile;
	infile.open(filename);
	if (infile == NULL)
	{
		cout << "NOT EXISTS FILE\n";
	}
	else
		while (!infile.eof())
		{
			size++;
            int *p=new int[size];
            for (int j=0; j<size-1; j++)
            	p[j]=element[j];
			infile >> p[size-1];
            delete[] element;
            element=p;
		}
	infile.close();
	size--;
	last = size-1;

	if(last==0 && element[0]>1000000)
	{
        delete [] element;
        element = NULL;
    	last = -1;
    	size = 0;
    }
}

DArrayList::DArrayList(const DArrayList & someList){  //copy constructor

    last = someList.last;
    size = someList.size;
    element = new int[size];
    for(int i = 0 ; i < size; i++){
        element[i] = someList.element[i];
    }
}

void DArrayList::operator=(const DArrayList & someList){
    if (size < someList.size)
	{
		delete[] element;
		size = someList.size;
		element = new int[size];
	}
    for(int i = 0 ; i < someList.size; i++)
        element[i] = someList.element[i];
    last=size-1;
}

bool DArrayList::empty() const{
    return last == -1;
}

int DArrayList::length() const{
    return last + 1;
}

void DArrayList::insert(const int x, int i){
	size++;
	int *p=new int[size];
    for (int j=0; j<i; j++)
    	p[j]=element[j];
    for (int j=i; j<=last; j++)
    	p[j+1]=element[j];
	p[i]=x;
    delete[] element;
    element=p;
    last++;
}

void DArrayList::append(const int x){
	size++;
	int *p=new int[size];
    for (int j=0; j<=last; j++)
    	p[j]=element[j];
    last++;
	p[last]=x;
    delete[] element;
    element=p;
}

void DArrayList::erase(int i){
    for(int j = i; j < size; j++){
        *(element+j+1) = *(element+j);
    }
    size--; last--;
}

int& DArrayList::at(int i){
    assert(last >= 0 && i <= last && i >= 0);
    return element[i];
}

void DArrayList::print() const{
    if(empty()){
        cout << "List Empty";
    }else{
        for(int i = 0; i <  size; i++){
            cout << *(element+i) << "   " ;
        }
    }
}

int main(){
    cout << "Chuong trinh test KDLTT danh sach so nguyen" << endl;
    cout << "Tac gia: [LocVU]\n--------------------" << endl;

    cout << "L1: L1.append(3);L1.append(4);L1.append(5);"
        << "L1.insert(2, 0); L1.insert(1, 0); L1.insert(3, 2);" << endl;

    DArrayList L1; L1.print(); cout << endl;
    L1.append(3); L1.print(); cout << endl;
    L1.append(4); L1.print(); cout << endl;
    L1.append(5); L1.print(); cout << endl;

    L1.insert(2, 0); L1.print(); cout << endl;
    L1.insert(1, 0); L1.print(); cout << endl;
    L1.insert(3, 2); L1.print(); cout << endl;


    cout << "\nL2: L2.append(4);L2.append(4);L2.append(1);"
        << "L2.erase(2); L2.insert(5, 1); L2.insert(3, 2);" << endl;

    DArrayList L2;
    L2.append(4);
    L2.append(4);
    L2.append(1);
    L2.print();
    cout << endl;
    L2.erase(2);
    L2.insert(5, 1);
    L2.insert(3, 2);

    cout << "L2.at(3): " << L2.at(3) << endl;
    L2.print();
    cout << endl;

    cout << "\nL3: input.txt" << endl;
    DArrayList L3("input.txt");
    L3.print();
    cout << endl;

    cout << "\nL4(L3);L4.insert(10, 0);" << endl;
    DArrayList L4(L3);
    L4.insert(10, 0);
    L4.print();
    cout << endl;

    cout << "\nL4 = L1" << endl;
    L4 = L1;
    L4.print();
    cout << endl;

//    getch();
    return 0;
}
