#pragma once
#include "Heap.h"
#include "SearchTree.h"
class HoffmanHeap : public Heap
{	
	private:
		void buildHeapFromTree(BiTreeNode* root);
	
	public:
		HoffmanHeap(SearchTree& tree);
		HoffmanHeap():Heap(127){}
		~HoffmanHeap();
		BiTree& buildCodedTree();

};

