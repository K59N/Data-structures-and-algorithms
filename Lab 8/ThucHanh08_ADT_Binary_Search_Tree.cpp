 //! @Filename ThucHanh08_ADT_Binary_Search_Tree.cpp
 //! @Author LocVU
 //! @Creaton 28.10.15

#include <iostream>
#include <fstream>
//#include <conio.h>
using namespace std;

// Dinh nghia cau truc 1 dinh
struct Node{
    int key;
    Node * parent;
    Node * right;
    Node * left;
    Node(int v){
        key = v;
        parent = NULL;
        right = NULL;
        left = NULL;
    }
    Node() {
        parent = NULL;
        right = NULL;
        left = NULL;
    }
};

class BstSet{
public:
    BstSet();
    BstSet(char *filename);
    ~BstSet;
    bool find(int x) const;
    void earse(int x);
    void insert(int x);
    int min() const;
    int max() const;
    int predecessor(int x) const;
    int successor(int x) const;
    void printInoder() const;
private:

};

BstSet::BstSet(){

}

// Chuong trinh chinh
int main(){

//    getch();
    return 0;
}
