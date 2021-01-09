#pragma once
#include "Heap.h"
#include "SearchTree.h"
enum SIZE {
	ASSCII = 128
};
/// <summary>
/// This class is an instance of a heap. it can create the BiTree for the huffman code
/// </summary>
class HoffmanHeap : public Heap
{	
	public:
		HoffmanHeap(BiTree arr[], int size);
		HoffmanHeap():Heap(ASSCII){}
		~HoffmanHeap();
		//creates the huffman tree from the heap using the algorithem.
		BiTree& buildCodedTree();

};

