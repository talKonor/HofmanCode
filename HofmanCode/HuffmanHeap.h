#pragma once
#include "Heap.h"
#include "SearchTree.h"
enum SIZE {
	ASSCII = 128
};
/// <summary>
/// This class is an instance of a heap. it can create the BiTree for the huffman code
/// </summary>
class huffmanHeap : public Heap
{	
	public:
		huffmanHeap(BiTree arr[], int size);
		huffmanHeap():Heap(ASSCII){}
		~huffmanHeap();
		//creates the huffman tree from the heap using the algorithem.
		BiTree& buildCodedTree();

};

