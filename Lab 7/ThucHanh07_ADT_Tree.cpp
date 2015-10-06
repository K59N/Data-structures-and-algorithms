#include <iostream>
#include <conio.h>
using namespace std;

// Dinh nghia cau truc 1 dinh
struct Node{
    int data;
    Node * parent;
    Node * firstChild;
    Node * nextSibling;
    Node(int v){
        data = v;
        parent = NULL;
        firstChild = NULL;
        nextSibling = NULL;
    }
};

// Tao cay nhu trong trang 6 slides
// A: 1, B: 2, C: 3, D: 4, E: 5, F: 6, G:7
// Tuong duong file tree_demo.txt
Node * buildTestTree(){
    Node * n1 = new Node(1);
    Node * n2 = new Node(2);
    n1->firstChild = n2;
    n2->parent = n1;
    
    Node * n3 = new Node(3);
    n1->firstChild->nextSibling = n3;
    n3->parent = n1;
    
    Node * n4 = new Node(4);
    n1->firstChild->nextSibling->nextSibling = n4;
    n4->parent = n1;
    
    Node * n5 = new Node(5);
    n2->firstChild = n5;
    n5->parent = n2;
    
    Node * n6 = new Node(6);
    n2->firstChild->nextSibling = n6;
    n6->parent = n2;
    
    Node * n7 = new Node(7);
    n4->firstChild = n7;
    n7->parent = n4;
    
    return n1;
}

// In cay goc o root theo thu tu truoc (preorder)
void printPreorder(Node * root){
    if(root){
        cout << root->data << " ";
        Node * p = root->firstChild;
        while(p){
            printPreorder(p);
            p = p->nextSibling;
        }
    }
}

// Chuong trinh chinh
int main(){
    Node * root1 = buildTestTree();
    printPreorder(root1);
    getch();
    return 0;
}
