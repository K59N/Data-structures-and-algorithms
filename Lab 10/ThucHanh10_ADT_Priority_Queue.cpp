#include <iostream>
//#include <conio.h>
#include <assert.h>
#include <fstream>
using namespace std;

// Dinh nghia cau truc 1 dinh
struct Node{
    int key;
    char data;
    Node * left;
    Node * right;
    Node * parent;
    Node (int k, char d){
    	key = k;
    	data = d;
    	left = right = parent = NULL;
    }
};

class PriorityQueue{
	public:
		PriorityQueue();
		PriorityQueue(const char * filename);
		~PriorityQueue();
		char findMin();                     // Tim gia tri nho nhat
		void insert(int k, char d);         // Chen them 1 Node
		void removeMin();                   // Xoa root
		void print();                       //


	private:
		Node * root;
		Node * last;
		void upHeap();                                      // Duyet tu last len
		void downHeap();                                    // Duyet tu root xuong
		void swapNodeData(Node * pNode1, Node * pNode2);    // Dao cho 2 Node
		void printC(Node * pNode);
};

PriorityQueue::PriorityQueue(){
	root = last = NULL;
}

PriorityQueue::PriorityQueue(const char * filename){
	root = last = NULL;
	ifstream infile(filename);
	if(!infile.good()){
        cout << filename << " doesn't exist!" << endl;
        return;
	}
	int data;
	char c;
	while(!infile.eof()){
        infile >> data >> c ;
        insert(data, c);
	}
	infile.close();
}

PriorityQueue::~PriorityQueue(){

}

char PriorityQueue::findMin(){
	return root->data;
}

void PriorityQueue::insert(int k, char d){
	if (root == NULL){
        last = root;
	}
    else if (root == last){
        last = root->left;
        last->parent = root;
    }else{
    	if (last == last->parent->left){
    		last = last->parent->right;
    	}
    	else{
            while( last == last->parent->right){
                last = last->parent;
                if(last == root)
                    break;
                if( last == last->parent->left){
                    last = last->parent->right;
                    break;
                }
            }
            while( last->left != NULL){
                last = last->left;
            }
        }
    }
    last->key = k;
    last->data = d;
//	upHeap();
}

void PriorityQueue::removeMin(){
	if (root == NULL){

	}else if (root == last){
		delete root;
		delete last;
		root = last = NULL;
	}else{
		// doi cho du lieu root voi last
		swapNodeData(root, last);
		Node * pNode = last;
		if (pNode == pNode->parent->right){
			// ma cua ban de cap nhat con tro last
		}
		else{
			// ma cua ban de cap nhat con tro last
			// su dung con tro phu pNode
			// di nguoc len toi root hoac toi right
    		// neu right chuyen sang left
    		// roi di xuong theo right toi NULL
			// cap nhat last
		}
		if (last == last->parent->left){
			last->parent->left = NULL;
		}else{
			last->parent->right = NULL;
		}
		delete last;
		last = pNode;
		downHeap();
	}
}

void PriorityQueue::print(){
	printC(root);
}

void PriorityQueue::upHeap(){
    Node * cur = last;
    do{
        if(cur->key < cur->parent->key){
            swapNodeData(cur, cur->parent);
        }
        cur = cur->parent;
    }
    while (cur != root);
}

void PriorityQueue::downHeap(){
    Node * cur = root;
    while(cur->left != NULL && cur->right != NULL){
        if( cur->left->key < cur->right->key ){
            swapNodeData(cur, cur->left);
            cur = cur->left;
        }else{
            swapNodeData(cur, cur->right);
            cur = cur->right;
        }
    }
}

void PriorityQueue::swapNodeData(Node * pNode1, Node * pNode2){
	int k = pNode1->key;
	char d = pNode1->data;
	pNode1->key = pNode2->key;
	pNode1->data = pNode2->data;
	pNode2->key = k;
	pNode2->data = d;
}

void PriorityQueue::printC(Node * pNode){
	if (pNode == NULL) return;
	printC(pNode->left);
	cout << pNode->key << " " << pNode->data << "\n";
	printC(pNode->right);
}

// Chuong trinh chinh
int main(){
	PriorityQueue pq1 = PriorityQueue();
 //   PriorityQueue pq2 = PriorityQueue("ThucHanh10_ADT_Priority_Queue.input.txt");
	// voi thu tu insert sau day
	// thu tu cha con luon dung
	// ham upHeap() se ko lam gi
	pq1.insert(4, 'C');
	pq1.insert(5, 'A');
	pq1.insert(6, 'Z');
	pq1.insert(15, 'K');
	pq1.insert(9, 'F');
	pq1.insert(7, 'Q');
	pq1.insert(20, 'B');
	pq1.insert(16, 'X');
	pq1.insert(25, 'J');
	pq1.insert(14, 'E');
	pq1.insert(12, 'H');
	pq1.insert(11, 'S');
	pq1.insert(18, 'W');
	pq1.print();
	return 0;
}
