//! @Filename ChainHash.cpp
//! @Author LocVU
//! @Creaton 11.11.15
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

class ChainHash{
    public:
        static const int SIZE = 31;                 // Kich thuoc bang bam - So nguyen to thoa man 4k+3
        ChainHash();
//        ChainHash(const ChainHash & Table);
//        ~ChainHash();
//        void operator=(const ChainHash &Table);
        bool search(string dict);                   // Tim dict co trong bang bam hay khong
        void insert(const string & dict);           // Chen dict tu tu dien vao bang bam
        void print();                               // In bang bam
        void readFile(const char * filename);       // Doc tu dien
        void findInFile(const char * filename);     // Tim tu trong file input
    private:
        struct Node{            // Cau truc 1 Node trong slot
            string data;
            Node *next;
        };
        Node * T[SIZE];
        unsigned int Hash(string dict);
        string str;
};


ChainHash::ChainHash(){
    for(int i = 0; i < SIZE; i++){
        T[i] = NULL;                    // Khoi tao Node dau tien cua cac Slot la NULL
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
    if(p != NULL and search(dict) == false){
        p->data = dict;
        p->next = T[i];
        T[i] = p;                        //Xen vao dau day chuyen
    }
}

void ChainHash::print(){
    for(int i=0; i < SIZE; i++){
        cout << "Slot " << i << "   ";
        for(Node * p = T[i]; p != NULL; p = p->next){
            cout << p->data << " - " ;
        }
        cout << endl;
    }
}

void ChainHash::readFile(const char * filename){
    ifstream infile(filename);
    if(!infile.good()){
        cout << filename << " doesn't exist !" << endl;
    }
    while(!infile.eof()){
        getline(infile, str, ' ');
        insert(str);
    }
    infile.close();
}

void ChainHash::findInFile(const char * filename){
    ifstream infile(filename);
    if(!infile.good()){
        cout << filename << " doesn't exist !" << endl;
    }
    while(!infile.eof()){
        getline(infile, str, ' ');
        if(!search(str)){
            cout << str << endl;
        }
    }
    infile.close();
}

int main(){
//    string dict, str;
    ChainHash chh;
    chh.readFile("dictionary.txt");

    cout << "Bang bam :  " << endl;
    chh.print();
    cout << "Tim kiem cac tu trong file input.txt khong co trong tu dien \n" << endl;
    chh.findInFile("input.txt");

    return 0;
}
