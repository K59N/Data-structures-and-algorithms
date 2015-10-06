#include <iostream>
#include <fstream>
#include <conio.h>
using namespace std;

// Kieu Node bieu dien 1 nut trong DSLK don
struct Node{
    int data;
    Node * next;
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

// Chuong trinh chinh
int main(){
    cout << "Chuong trinh demo DSLK don." << endl;
    cout << "Tac gia: [Your name please]\n--------------------" << endl;
    Node * head1, * head2;
    head1 = NULL; // Khoi tao DSLK1 rong
    head2 = NULL; // Khoi tao DSLK2 rong    
    readFile(head1, "numbers1.txt");
    readFile(head2, "numbers2.txt");
//    print(head1);
//    cout << endl;
//    print(head2);
    cout << "\nXong!" << endl;
    
    getch();
    return 0;
}
