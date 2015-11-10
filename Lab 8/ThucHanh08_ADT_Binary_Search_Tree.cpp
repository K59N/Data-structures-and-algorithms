/*
| ThucHanh08_ADT_Binary_Search_Tree.txt
| 7
| 4
| 11
| 3
| 6
| 8
| 13
| 17
| 15
| 18
|
|*/


 //! @Filename ThucHanh08_ADT_Binary_Search_Tree.cpp
 //! @Author LocVU
 //! @Creaton 2.11.15


#include <iostream>
#include <fstream>
#include <cassert>
#include <stdlib.h>
//#include <conio.h>

using namespace std;

// Dinh nghia cau truc 1 dinh

struct Node{
    int key;
    Node * left;
    Node * right;
    Node * parent;
    Node(int x){
        key = x;
        parent = NULL;
        left = NULL;
        right = NULL;
    }
    Node(){
        parent = NULL;
        left = NULL;
        right = NULL;
    }
};

class BstSet{
	public:
        BstSet();
        Node *findNode(int value) const;
        BstSet(const char * filename);
        ~BstSet();
        bool find(int x) const;
        void erase(int x);
        void insert(int x);
        int min() const;
        int max() const;
        int predecessor(int x) const;
        int successor(int x) const;
        void printInorder() const;
	private:
		Node * root;
		void makeEmpty(Node *);
		void printInorder(Node *) const ;
};

BstSet::BstSet(){
	root = NULL;
}
//Tim kiem Node cua value
Node * BstSet::findNode( int value) const{
    Node * tmp = root;
    while(1){
        if(value < tmp->key)
            if(tmp->left == NULL)
                return tmp;
            else
                tmp = tmp->left;
        else if(value > tmp->key)
            if(tmp->right == NULL)
                return tmp;
            else
                tmp = tmp->right;
        else if(value == tmp->key)
            return tmp;
        else
            return NULL;
    }
}
//Doc du lieu tu file
BstSet::BstSet(const char * filename){
    ifstream is(filename);
	if(is.is_open()){

        int value;
        root = NULL;
        while(!is.eof()){
            is >> value;
            insert(value);
        }
	}else{
        cout << "Not found file!" << endl;
	}
	is.close();
}
//Giai phong bo nho cho tat ca cac Node
void BstSet::makeEmpty(Node *p){
    if(p == NULL){
        return;
    }
    if(p->left == NULL && p->right == NULL){
        if(p->parent == NULL){
            delete root;
            root = NULL;
            return;
        }
        Node * par = p->parent;
        if(par != NULL){
            if(par->left == p){
                par->left = NULL;
            }
            if(par->right == p){
                par->right = NULL;
            }
        }
        delete p;
        makeEmpty(par);
    }
    if(p->left != NULL){
        makeEmpty(p->left);
    }
    if(p->right != NULL){
        makeEmpty(p->right);
    }
}

BstSet::~BstSet(){
    makeEmpty(root);
}

//Tim x co trong cay hay khong
bool BstSet::find(int x) const{
    Node * tmp = root;
    while(1){
        if(tmp == NULL)
            break;
        if(x == tmp->key){
            return true;
        }else if(x < tmp->key){
            if(tmp->left != NULL)
                tmp = tmp->left;
            else
                break;
        }else if(x > tmp->key){
            if(tmp->right != NULL)
                tmp = tmp->right;
            else
                break;
        }
    }
	return false;
}

void BstSet::erase(int x){
    if(!find(x)){
        cout << "Not found " << x << " in binary tree !" << endl;
        return;
    }
    Node *p = findNode(x);
    if(p->left == NULL && p->right == NULL){
        Node *par = p->parent;
        if(par->left == p){
            par->left = NULL;
        }
        if(par->right == p){
            par->right = NULL;
        }
        delete p;
        return;
    }
    if(p->left != NULL && p->right != NULL){
        Node * tmp = findNode(successor(x)); // tmp co 2 kha nang: co con phai hoac khong co con nao
        p->key = tmp->key;

        if(tmp->right != NULL){
            p->right = tmp->right;
            tmp->right->parent = p;
        }
        if(tmp->right == NULL){
            Node *tmp2 = tmp->parent;
            if(tmp2->right == tmp)
                tmp2->right = NULL;
            if(tmp2->left == tmp)
                tmp2->left = NULL;
        }
        delete tmp;
        return;
    }
    if(p->right != NULL){
        Node *par = p->parent;
        par->right = p->right;
        p->right->parent = par;
        delete p;
        return;
    }
    if(p->left != NULL){
        Node *par = p->parent;
        par->left = p->left;
        p->left->parent = par;
        delete p;
        return;
    }
}


//Them Node vao cay
void BstSet::insert(int x){
    if(find(x)){
        cout << "The value existed!" << endl;
        return;
    }
    if(root == NULL){
        root = new Node();
        root->key = x;
        return ;
    }
    Node *tmp1 = findNode(x);
    Node *tmp2 = new Node(x);
    if(x < tmp1->key)
        tmp1->left = tmp2;
    if(x > tmp1->key)
        tmp1->right = tmp2;
    tmp2->parent = tmp1;
}
//Gia tri min
int BstSet::min() const{
    Node *p = root;
    while(p->left != NULL){
        p = p->left;
    }
	return p->key;
}
//Gia tri max
int BstSet::max() const{
	Node *p = root;
    while(p->right != NULL){
        p = p->right;
    }
	return p->key;
}
//Tim khoa lien truoc x
int BstSet::predecessor(int x) const{
    assert(root != NULL && find(x));
	Node *p = findNode(x);
	if(x == min()){
 //       cout << "Not value is predecessor of "<< x << endl;
        return x;
	}
	if (p->left != NULL){
        p = p->left;
        while (p->right != NULL){
            p = p->right;
        }
        return p->key;
	}

	Node * par = p->parent;
	while (par != NULL && p == par->left){
        p = par;
        par = par->parent;
	}
	return par->key;

}
//Tim khoa lien sau x
int BstSet::successor(int x) const{
    assert(root != NULL && find(x));
	Node *p = findNode(x);
	if(x == max()){
  //      cout << "Not value is successor of "<< x << endl;
        return x;
	}

	if(p->right != NULL){
        p = p->right;
        while(p->left != NULL)
            p = p->left;
        return p->key;
	}

    Node * par = p->parent;

    while(par != NULL && p == par->right){
            p = par;
            par = par->parent;
    }
    return par->key;
}
//In trong
void BstSet::printInorder(Node * p) const{
    if(p == NULL)
        return;
    printInorder(p->left);
    cout << p->key << " " ;
    printInorder(p->right);
//    if(p != NULL){
//        if(p->left)
//            printInorder(p->left);
//        cout << p->key << "  ";
//        if(p->right)
//            printInorder(p->right);
//        else
//            return;
//    }
}
void BstSet::printInorder() const{
    if(root == NULL)
        cout << "Empty "<< endl;
    printInorder(root);  //goi ham private

}

// Chuong trinh chinh
int main(){
    cout << "Read tree from file: ThucHanh08_ADT_Binary_Search_Tree.txt" << endl;
    BstSet bst("Test.txt");
    while(1){
        cout << "\n\nBinary Search Tree Program " << endl << "Creat by LocVU" << endl;
        cout << "==========================" << endl;
        cout << "0. Exit" << endl;
        cout << "1. Print In Order" << endl;
        cout << "2. Insert" << endl;
        cout << "3. Erase" << endl;
        cout << "4. Find" << endl;
        cout << "5. Min" << endl;
        cout << "6. Max" << endl;
        cout << "7. Predecessor" << endl;
        cout << "8. Successor" << endl;
        cout << "9. Destroy tree" << endl;
        cout << "Enter the choice ";
        int ch, x;
        cin >> ch;
        switch(ch){
            case 0:
                return 0;
            case 1:
                cout << "Tree: " ;
                bst.printInorder();
                break;
            case 2:
                cout << "The value to insert: " ;
                cin >> x;
                bst.insert(x);
                break;
            case 3:
                cout << "The value to erase: " ;
                cin >> x;
                bst.erase(x);
                break;
            case 4:
                int fin;
                cout << "The value to find: " ;
                cin >> x;
                if(bst.find(x))
                    cout << x << " in this tree" << endl;
                else
                    cout << x << " not in this tree" << endl;
                break;
            case 5:
                cout << "The min value: " << bst.min() << endl;
                break;
            case 6:
                cout << "The max value: " << bst.max() << endl;
                break;
            case 7:
                cout << "The predecessor of " ;
                cin >> x;
                cout << "                is " << bst.predecessor(x) << endl;
                break;
            case 8:
                cout << "Successor of " ;
                cin >> x;
                cout << "              is " << bst.successor(x) << endl;
                break;
            case 9:
                bst.~BstSet();
                cout << "DONE" << endl;
                break;
        } // END SWITCH
        char c;
        cout << "\nAre you continue ? y/n? ";
        cin >> c;
        if (c != 'y'){
            exit(1);
        }
    }
	return 0;
}
