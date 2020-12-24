#include "SearchTree.h"
#include<iostream>
#include "Heap.h"
using namespace std;
void printTree(BiTreeNode* t1);
void insertToheap(Heap& h1, BiTreeNode* t1);
int main() {
	SearchTree t1;
	Node n1;
	Heap h1(10);
	int num1=5;
	for (int i = 0; i < 10; i++) {
		n1.setFreq(num1);
		n1.setCh('a' + i);
		t1.insert(n1);
		num1 = rand() % 10;
	}
	printTree(t1.root);
	insertToheap( h1, t1.root);
	int size = h1.getHeapSize();
	for (int i = 0; i < size; i++) {
		BiTree temp = h1.DeleteMin();
		cout << temp.root->data.getChar() << " : " << temp.root->data.getFreq() << endl;
	}

}

void insertToheap(Heap& h1, BiTreeNode* t1) {
	if (t1 == nullptr)
		return;
	else
	{
		
		insertToheap(h1, t1->left);
		h1.Insert(BiTree(t1));
		insertToheap(h1, t1->right);
		t1->left = nullptr;
		t1->right = nullptr;
		return;
	}
}

void printTree(BiTreeNode* t1) {

	if (t1 == nullptr)
		return;
	else {
		printTree(t1->left);
		cout << t1->data.getChar() << ":" << t1->data.getFreq() << endl;
		printTree(t1->right);
	}
}