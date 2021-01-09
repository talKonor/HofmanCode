#include "HoffmanHeap.h"


HoffmanHeap::HoffmanHeap(BiTree A[], int n) :Heap(A, n)
{
}

HoffmanHeap::~HoffmanHeap()
{
}

BiTree& HoffmanHeap::buildCodedTree()
{
	BiTree min1, min2,unionTree;
	if (heap_size == 1) {
		unionTree.root = new BiTreeNode();
		min1 = DeleteMin();
		unionTree.root->right = min1.root;
		unionTree.root->data.setFreq(min1.root->data.getFreq());
		Insert(unionTree);

	}
	while (heap_size != 1) {
		unionTree.root = new BiTreeNode();
		min1 = DeleteMin();
		min2 = DeleteMin();
		unionTree.root->left = min1.root;
		unionTree.root->right = min2.root;
		unionTree.root->data.setFreq(min1.root->data.getFreq() + min2.root->data.getFreq());
		Insert(unionTree);
	}
	min1.root = nullptr;
	min2.root = nullptr;
	unionTree.root = nullptr;
	return arr[0];
}

