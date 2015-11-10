//! @Filename ThucHanh08_ADT_Binary_Search_Tree.cpp
//! @Author LocVU
//! @Creaton 11.11.15
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

class ChainHash{
    public:
        static const int SIZE = 31;
        ChainHash();
//        ChainHash(const ChainHash & Table);
//        ~ChainHash();
//        void operator=(const ChainHash &Table);
        bool search(string dict);
        void insert(const string & dict);
        void print();
    private:
        struct Node{
            string data;
            Node *next;
        };
        Node * T[SIZE];
        unsigned int Hash(string dict);
};


ChainHash::ChainHash(){
    for(int i = 0; i < SIZE; i++){
        T[i] = NULL;
    }
}

unsigned int ChainHash::Hash(string dict){
    int value = (int) dict[0];
    return value%SIZE;
}

bool ChainHash::search(string dict){
    int i = Hash(dict);
    Node *p = T[i];
    while(p != NULL)
        if(p->data == dict){
            return true;
        }else{
            p = p->next;
        }
    return false;
}

void ChainHash::insert(const string &dict){
    int i = Hash(dict);
    Node *p = new Node;
    if(p != NULL){
        p->data = dict;
        p->next = T[i];
        T[i] = p;  //Xen vao dau day chuyen
    }else{
        cout << "Tu " << dict << "da xuat hien o slot " << i << endl;
    }
}

void ChainHash::print(){
    for(int i=0; i < SIZE; i++){
        cout << "Slot " << i << "   ";
        for(Node * p = T[i]; p != NULL; p = p->next){
            cout << p->data << " -> " ;
        }
        cout << endl;
    }
}

int main(){
    string dict, str;
    ChainHash chh;
    ifstream infile("dictionary.txt");
    if(!infile.good()){
        cout << "dictionary.txt doesn't exist !" << endl;
        cin.ignore();
        cin.get();
    }
    while(!infile.eof()){
        getline(infile, str, ' ');
        chh.insert(str);
    }
    infile.close();

    cout << "Bang bam :  " << endl;
    chh.print();
    cout << "Tim kiem cac tu trong file input.txt khong co trong tu dien \n" << endl;

    infile.open("input.txt");
    if(!infile.good()){
        cout << "input.txt doesn't exist !" << endl;
        cin.ignore();
        cin.get();
    }
    while(!infile.eof()){
        getline(infile, str, ' ');
        if(!chh.search(str)){
            cout << str << endl;
        }
    }
     infile.close();

    return 0;
}
