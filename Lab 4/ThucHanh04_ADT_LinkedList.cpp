//! @author: Loc VU
//! Created on 1.Oct.15

//! \brief : Complete source code in this file

#include <iostream>
#include <fstream>
#include <cassert>
//#include <conio.h>
using namespace std;

// Kieu Node bieu dien 1 nut trong DSLK don
struct Node{
    int data;    //so nguyen
    Node * next; //dia chi nut tiep theo
};

// Them nut chua value vao dau DSLK
void addFirst(Node *& head, int value){
    // tao nut moi
    Node * tmp = new Node;
    tmp->data = value;
    tmp->next = NULL;

    if(head == NULL){
        // them trong truong hop DS rong
        head = tmp;
    } else{
        // them trong truong hop DS khong rong
        tmp->next = head;
        head = tmp;
    }
}

// Doc day so trong tep co ten filename vao DSLK
void readFile(Node *& head, char * filename){
    ifstream fin(filename);
    if(!fin.good()){
        cout << "Loi doc file " << filename << endl;
        return;
    }
    int v;
    while(fin >> v) addFirst(head, v);
    fin.close();
}

void print(Node *& head){
    Node * tmp = new Node;
    if (head == NULL){
        cout << "This list  is empty!";
    }else{
        for(tmp = head; tmp!= NULL; tmp = tmp->next){
            cout << tmp->data << endl;

        }
    }
}

//Tim gia tri "value" co trong "head1" va "head2" hay khong
void find(Node *& head1, Node *& head2 , int value){
    Node * tmp = new Node;
    if (head1 == NULL && head2 == NULL){
        cout << "Not found!" << endl;
    }else{

        for(tmp = head1; tmp!= NULL; tmp = tmp->next){
            if(value == tmp->data){
                cout << value << " have in list 1" << endl;
            }
        }
        for(tmp = head2; tmp!= NULL; tmp = tmp->next){
            if(value == tmp->data){
                cout << value << " have in list 2" << endl;
            }
        }
    }
}

// Chuong trinh chinh
int main(){
    cout << "Chuong trinh demo DSLK don." << endl;
    cout << "Tac gia: [LocVU]\n--------------------" << endl;
    Node * head1, * head2;
    head1 = NULL; // Khoi tao DSLK1 rong
    head2 = NULL; // Khoi tao DSLK2 rong
    readFile(head1, "numbers1.txt");
    readFile(head2, "numbers2.txt");
    cout << "File 1: " << endl;
    print(head1);
    cout << endl;
    cout << "File 1: " << endl;
    print(head2);


    find(head1, head2, 43);
    cout << "\nXong!" << endl;

//    getch();
    return 0;
}
