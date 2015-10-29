/* File ThucHanh07_ADT_Tree.txt
 * ----------------------------
 * 7
 * 1 2
 * 1 3
 * 1 4
 * 2 5
 * 2 6
 * 4 7
 */
 //! @Filename ThucHanh07_ADT_Tree.cpp
 //! @Author LocVU
 //! @Creaton 28.10.15

#include <iostream>
#include <fstream>
//#include <conio.h>
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
    Node() {
        parent = NULL;
        nextSibling = NULL;
        firstChild = NULL;
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

    Node * n8 = new Node(8);
    n6->firstChild = n8;
    n8->parent = n6;

    Node * n9 = new Node(9);
    n6->firstChild->nextSibling = n9;
    n9->parent = n6;

    return n1;
}
//Tim kiem Node p trong cay
Node *findNode(Node *root, Node *p){
    if(p->data == root->data) return root;          // Neu p la root
    if(root->firstChild != NULL){                   // Xet p la firstChild
        if( findNode(root->firstChild, p)!= NULL )
            return findNode(root->firstChild, p);
    }
    if(root->nextSibling != NULL){                  // Xet p la nextSibling
        if( findNode(root->nextSibling, p)!= NULL )
            return findNode(root->nextSibling, p);
    }
    return NULL;
}

// Them 1 Node vao cay
void addNode(Node * &root, Node *parent, Node *child){
    if (root->firstChild == NULL ){                 // Root chi co 1 phan tu
        root = new Node(parent->data);
        root->firstChild = new Node(child->data);
        root->firstChild->parent = root;
    }else{
        Node * p = findNode(root, parent);
        if(p->firstChild == NULL){                  // p la la
            p->firstChild = new Node(child->data);
            p->firstChild->parent = p;
        }else{                                      // p khong phai la
            p = p->firstChild;                      // tro xuong Node con cua p
            while(p->nextSibling != NULL)
                p = p->nextSibling;                 // tro den Node con cuoi cung
            p->nextSibling = new Node(child->data);
            p->nextSibling->parent = p->parent;
        }
    }
}

//Doc 1 cay tu file
void readTree(Node *&root, const char * filename){
    ifstream is(filename);
    Node *parent = new Node();
    Node *child = new Node();
    int n, par, chi;
    if(is.is_open()){
        is >> n;                    // So Node trong cay
        while (!is.eof()){
            is >> par >> chi;       // Doc Node parent va child
            parent->data = par;
            child->data = chi;
            addNode(root, parent, child);
        }
    }else{
        cout << "Not found!";
    }
    is.close();
}

// In cay goc o root theo thu tu truoc (preorder)
void printPreorder(Node * root){
    if(root){
        cout << root->data << " ";
        Node * p = root->firstChild;        // p la con dau tien cua root
        while(p){
            printPreorder(p);
            p = p->nextSibling;
        }
    }
}

// In cay goc o root theo thu tu sau (postorder)
void printPostorder(Node * root){
    if(root){
        Node *p = root->firstChild;
        while(p){
            printPostorder(p);
            p = p->nextSibling;
        }
          cout << root->data << " ";
    }
}

// In cay goc o root theo thu tu trong (inorder)
void printInorder(Node * root){
    if(root){
        Node *p = root->firstChild;
        if(p){
            printInorder(p);
        }
          cout << root->data << " ";
        while(p){
            p = p->nextSibling;
            printInorder(p);
        }
    }
}
// Tinh do sau tu dinh p
int deep(Node * p){
    int count = 0;      // Dem so sau
    while(p->parent != NULL){
        count++;
        p = p->parent;
    }
    return count;
}

// Tinh do cao cua cay
int height(Node * root){
    static int maxDeep = 1;   //Do sau lon nhat cua cay
    if (root){
        Node *p = root->firstChild;
        if(deep(root) > maxDeep){
            maxDeep = deep(root) + 1;
        }
        while(p){
            height(p);
            p = p->nextSibling;
        }
    }
    return maxDeep;
}

//Xet cay co la cay nhi phan day du hay khong
int isBinaryTree(Node * root){
    if (root){
        Node *p = root->firstChild;
        if(p && p->nextSibling && !p->nextSibling->nextSibling){   // Co dung 2 Node child cua Node parent
            isBinaryTree(p);
            p = p->nextSibling;
        }else{
            return 0;
        }
        return 1;
    }
}
// Chuong trinh chinh
int main(){
   // Node * root1 = buildTestTree();
    Node * root1 = new Node;
    readTree(root1, "ThucHanh07_ADT_Tree.txt");

    Node * p = root1->firstChild->firstChild;

    cout << "Deep: " << deep(p) << endl;
    cout << "Height : " << height(root1) << endl;

    cout << "Print PreOder: ";
    printPreorder(root1);
    cout << endl;

    cout << "Print PostOrder: ";
    printPostorder(root1);
    cout << endl;

    if (isBinaryTree(root1)){
        cout << "Print InOrder: ";
        printInorder(root1);
    }else{
        cout << "This isn't binary tree!" << endl;
    }
//    getch();
    return 0;
}
