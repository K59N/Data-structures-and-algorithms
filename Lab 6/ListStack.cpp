//! @ File name: ListStack.cpp
//! @ Created by: LocVU
//! @ Date : 20/10/15

#include <iostream>
#include <assert.h>
using namespace std;

class ListStack{
public:
    ListStack();
    ListStack(const ListStack &S);  //copy constructor
    ~ListStack();
    ListStack & operator = (const ListStack &S);
    bool Empty() const;
    void Push(const int &x);
    int & Pop();
    int & GetTop() const;
private:
    struct Node{
        int data;
        Node *next;
        Node(const int &x)
        :data(x),next(NULL){}
    };
    Node *top;

};

ListStack::ListStack(){
     top = NULL;
}
ListStack::ListStack(const ListStack &S){
    if(S.Empty()){
        top = NULL;
    }else{
        Node *P = S.top;
        top = new Node(P->data);
        Node *Q = top;
        for (P = P->next; P != NULL; P = P->next){
            Q = Q->next = new Node(P->data);
        }
    }
}

ListStack::~ListStack(){
    Node *P;
    while(top != NULL){
        P  = top;
        top = top->next;
        delete P;
    }
}

ListStack & ListStack::operator=(const ListStack &S){
    S.~ListStack();
    top = S.top;
    return *this;
}
bool ListStack::Empty() const{
    return top == NULL;
}

void ListStack::Push(const int &x){
    Node *P = new Node(x);
    if(top == NULL)
        top = P;
    else{
        P->next = top;
        top = P;
    }
}

int & ListStack::Pop(){
    //assert(top >= 0);
    int object = top->data;
    Node *P = top;
    top = top->next;
    delete P;
    return object;
}

int & ListStack::GetTop() const{
    assert(top >= 0);
    return top->data;
}

void dec_to_bin(int value, ListStack &S){
    int mod;
    while (value > 0){
        mod = value % 2;
        S.Push(mod);
        value /= 2;
    }

}


int main(){
    int value;
    ListStack *S = new ListStack;
    cout << "Enter the value: " ;
    cin >> value;
    dec_to_bin(value, *S);
    while(! S->Empty()){
        cout << S->Pop();
    }
    delete S;
    return 0;
}
