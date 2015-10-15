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
//Chen x vao cuoi danh sach
void append(Node *& head, int x){
    Node *dt, *tmp;
    tmp = new Node;
    dt = head;
    tmp->data = x;
    tmp->next = NULL;
    if(head == NULL)
        head = tmp;
    while(dt->next != NULL){
        dt = dt->next;
    }

    dt->next = tmp;
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

// Doc nguoc day so trong tep co ten filename vao DSLK
void readFileReverse(Node *& head, char * filename){
    ifstream fin(filename);
    if(!fin.good()){
        cout << "Loi doc file " << filename << endl;
        return;
    }
    head = NULL;  //lam trong danh sach
    int v;
    while(fin >> v)
        addFirst(head, v);
    fin.close();
}

//Kiem tra danh sach rong
int empty(Node *& head){
    if(head == NULL)
        return 1;
}

//Chieu dai danh sach
int length(Node *& head){
    Node *dt;                 // Tao 1 con tro duyet
    int count = 0;
    dt = head;
    if(head == NULL){
        return count;
    }else{
        count++;
        while(dt->next != NULL){
            dt = dt->next;
            count++;
        }
        return count;
    }
}

//Tra ve phan tu vi tri i
Node* element(Node *& head, int i){
    Node *dt = new Node;
    dt = head;
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

//Chen phan tu x vao vi tri i
void insert(Node *& head, int i, int x){
    Node *dt, *tmp;
    tmp = new Node;
    int count = 0;
    dt = head;
    if ( i == 0 ){
        addFirst(head, x);
    }else{
        while(dt->next != NULL && count < i-1){
            dt = dt->next;
            count++;
        }
        tmp->data = x;
        tmp->next = dt->next;
        dt->next = tmp;
    }
}


//Xoa phan tu o vi tri i
void erase(Node *& head, int i){
    Node *dt, *tmp;
    int count = 0;
    tmp = new Node;
    dt = head;
    if (i == 0){
        head = dt->next;
        delete dt;
    }
    else{
        while(dt->next != NULL && count < i-1){
            dt = dt->next;
            count++;
        }

        tmp = dt->next;
        dt->next = dt->next->next;
        tmp->next = NULL;
    }
}

// Tinh tong cac so
int sumList(Node *& head){
    Node *dt;
    dt = head;
    int sum = 0;
    do{
        sum += dt->data;
        dt = dt->next;
    }while(dt->next != NULL);

    sum += dt->data; //cong phan tu cuoi cung
    return sum;
}

// Tim so be nhat trong dslk
int minList(Node *& head){
    Node *dt;
    dt = head;
    int min = dt->data;
    while (dt->next != NULL){
        if (dt->data < min){
            min = dt->data;
        }
        dt = dt->next;
    }

    //so sanh phan tu cuoi
    if (dt->data < min){
        min = dt->data;
    }
    return min;
}

// Tim so lon nhat trong dslk
int maxList(Node *& head){
    Node *dt;
    dt = head;
    int max = dt->data;
    while (dt->next != NULL){
        if (dt->data > max){
            max = dt->data;
        }
        dt = dt->next;
    }

//so sanh phan tu cuoi
    if (dt->data > max){
        max = dt->data;
    }
    return max;
}

//Xoa bo so le
void eraseOdd(Node *& head){
    Node *dt = head;
    int i = 0;
    while(dt != NULL){
        if(dt->data % 2){
            erase(head, i);
            dt = dt->next;
        }else{
            dt = dt->next;
            i++;
        }
    }
    if(dt->data % 2){
        erase(head, i);
    }

}

//In dslk
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

// Chuong trinh chinh
int main(){
    cout << "Chuong trinh demo DSLK don." << endl;
    cout << "Tac gia: [Loc VU]\n--------------------" << endl;
    Node * head1, * head2;
    head1 = NULL; // Khoi tao DSLK1 rong
    head2 = NULL; // Khoi tao DSLK2 rong
   // readFile(head1, "numbers1.txt");
  //  readFile(head2, "numbers2.txt");
    cout << "Read: " << endl;
    print(head1);
    cout << endl;
    print(head2);


    readFileReverse(head1, "numbers1.txt");
    readFileReverse(head2, "numbers2.txt");
    cout << "\nRead Reverse: " << endl;
    print(head1);
    cout << endl;
    print(head2);


    cout << "-----> Empty: ";
    empty(head1)==1?(cout << "Yes"<< endl):(cout << "No" << endl);

    cout << "-----> Length: " << length(head2) <<  endl;

    cout << "-----> Element: " << element(head1, 3)->data <<endl;

    cout << "-----> Insert 27 " << endl;
    insert(head1, 4, 27);
    print(head1);

    cout << "-----> Append 96 :" << endl;
    append(head1, 96);
    print(head1);

    cout << "-----> Erase 2 :" << endl;
    erase(head1, 9);
    print(head1);

    cout << "-----> Sum list :" <<  sumList(head1) << endl;
    cout << "-----> Max list :" <<  maxList(head1) << endl;
    cout << "-----> Min list :" <<  minList(head1) << endl;

    cout << "-----> EraseOdd :" << endl;
    eraseOdd(head1);
    print(head1);
    cout << "\DONE!" << endl;

//    getch();
    return 0;
}
