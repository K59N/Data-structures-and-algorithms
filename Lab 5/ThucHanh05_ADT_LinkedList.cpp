#include <iostream>
#include <fstream>
//#include <conio.h>
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

// Doc xuoi day so trong tep co ten filename vao DSLK
void readFile(Node *& head, char * filename){
    ifstream fin(filename);
    if(!fin.good()){
        cout << "Loi doc file " << filename << endl;
        return;
    }
    int v;
    Node *tmp, *dt;                 // *dt la con tro duyet
    do{
        fin >> v;
        tmp = new Node;
        tmp->data = v;

        if(head == NULL){           //list rong
            head = tmp;
            head->next = NULL;
        }else{                      //list khong rong
            dt = head;
            while(dt->next != NULL){ //duyet den cuoi danh sach
                dt = dt->next;
            }
            dt->next = tmp;
            tmp->next = NULL;
        }
    }while(!fin.eof());
    fin.close();
}


// Doc xuoi day so trong tep co ten filename vao DSLK
void readFileReverse(Node *& head, char * filename){
    ifstream fin(filename);
    if(!fin.good()){
        cout << "Loi doc file " << filename << endl;
        return;
    }
    int v;
    while(fin >> v) addFirst(head, v);
    fin.close();
}

//Kiem tra danh sach rong
int empty(Node *& head){
    if(head != NULL)
        return 1;
}

//Chieu dai danh sach
int length(Node *& head){
    Node *dt;                 // Tao 1 con tro duyet
    int count = 0;
    while(dt->next != NULL){
        dt = dt->next;
        count++;
    }
    return count;
}

Node* element(Node *& head, int i){
    Node *dt;
    int j = 0;
    if (head == NULL){
        return 0;
    }else{


        while (j != i){
            dt = dt->next;
            j++;
        }
        return dt;
    }
}

// Chuong trinh chinh
int main(){
    cout << "Chuong trinh demo DSLK don." << endl;
    cout << "Tac gia: [Loc VU]\n--------------------" << endl;
    Node * head1, * head2;
    head1 = NULL; // Khoi tao DSLK1 rong
    head2 = NULL; // Khoi tao DSLK2 rong
    readFile(head1, "numbers1.txt");
    readFile(head2, "numbers2.txt");
//    print(head1);
//    cout << endl;
//    print(head2);
    cout << "\nXong!" << endl;

//    getch();
    return 0;
}
