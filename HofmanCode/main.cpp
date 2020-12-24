#include "SearchTree.h"
#include<iostream>
using namespace std;
void printTree(BinaryTreeNode* t1);
int main() {
	BinaryTree t1;
	Node n1;
	int num1=5;
	for (int i = 0; i < 10; i++) {
		n1.setFreq(num1);
		n1.setCh('a'+i);
		t1.insert(n1);
		num1 = rand() % 10;
	}
	printTree(t1.root);
	int num = rand() % 10;
	t1.Delete(num);
	printTree(t1.root);
}

void printTree(BinaryTreeNode* t1) {

	if (t1 == nullptr)
		return;
	else {
		printTree(t1->left);
		cout << t1->value.getChar() << ":" << t1->value.getFreq() << endl;
		printTree(t1->right);
	}
}