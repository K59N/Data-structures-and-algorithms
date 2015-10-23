//! @ File name: ArrayQueue.cpp
//! @ Created by: LocVU
//! @ Date : 20/10/15

#include <iostream>
#include <assert.h>
//#include <conio.h>
using namespace std;

class ArrayQueue{
public:

    ArrayQueue (int m);
    ArrayQueue (const ArrayQueue &Q);
 //   ~ArrayQueue();
    ArrayQueue & operator=(const ArrayQueue &Q);
    bool isEmpty() const;
    void Enqueue(const int &x);
    int Dequeue();
    int GetHead();
    void print();
private:
    static const int MAX_SIZE = 100;
    int element[MAX_SIZE];
    int size, head, tail, length;
};

ArrayQueue::ArrayQueue(int m){
    size = m;
    head = 0;
    tail  = -1;
    length = 0;
}

ArrayQueue::ArrayQueue(const ArrayQueue &Q){
    size = Q.size;
    head = Q.head;
    tail = Q.tail;
    length = Q.length;
    for (int i = 0; i<length; i++){
        element[(head+i)%size] = Q.element[(head+i)%size];
    }
}

ArrayQueue & ArrayQueue::operator=(const ArrayQueue &Q){
        int element[Q.size];
        size = Q.size;
        tail = Q.tail;
        head = Q.head;
        length = Q.length;
        for(int i = 0 ; i <length ; i++){
            element[(head+i)%size] = Q.element[(head+i)%size];
        }
    return *this;
}



bool ArrayQueue::isEmpty() const{
    return length == NULL;
}
void ArrayQueue::Enqueue(const int &x){
    if (length < size ){
        if(tail < size-1){
            tail += 1;
        }else if(tail == size - 1){
            tail = 0;
        }
        element[tail] = x;
        length++;
    }else{
        cout << "Full oy";
    }
}

int ArrayQueue::Dequeue(){
    assert(length > 0);
    int data = element[head];
    if (length == 1){
        head = 0;
        tail = 1;
    }else if(head == size-1){
        head = 0;
    }else{
        head = (head + 1) % size;
    }
    length--;
    return data;
}

int ArrayQueue::GetHead(){
    assert(length > 0);
    return element[head];
}

void ArrayQueue::print(){
    for(int i = 0; i < length; i++){
        cout << element[(head+i)%size];
    }
}
int main(){
    ArrayQueue Q(5);
    if (Q.isEmpty()){
        cout << "Empty " << endl;
    }
    Q.Enqueue(9);
    Q.Enqueue(5);
    Q.Enqueue(3);
    Q.Enqueue(1);
    Q.Enqueue(0);
    cout << Q.isEmpty() << endl;
    cout << "Print : " ;
    Q.print();
    cout << endl;
    cout << "Head: " << Q.GetHead() << endl;
    cout << endl;
    while (!Q.isEmpty()){
        cout << Q.Dequeue() << "    ";
    }
    //getch();
    return 0;
}
