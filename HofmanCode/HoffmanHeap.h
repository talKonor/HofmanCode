#pragma once
#include "Heap.h"
#include "SearchTree.h"
class HoffmanHeap : public Heap
{	
	public:
		HoffmanHeap(BiTree A[], int n);
		HoffmanHeap():Heap(127){}
		~HoffmanHeap();
		BiTree& buildCodedTree();

};

