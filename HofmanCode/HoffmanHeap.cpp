#include "HoffmanHeap.h"

HoffmanHeap::HoffmanHeap(SearchTree& tree):Heap(127)//enum
{
	BiTreeNode* root = tree.root;
	buildHeapFromTree(root);
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

void HoffmanHeap::buildHeapFromTree(BiTreeNode* root)
{
	if (root == nullptr){
		return;
	}
	buildHeapFromTree(root->left);
	
	BiTree newTree;
	newTree.root = new BiTreeNode(*root);
	newTree.root->left = nullptr;
	newTree.root->right = nullptr;
	Insert(newTree);
	newTree.root = nullptr;
	buildHeapFromTree(root->right);

}