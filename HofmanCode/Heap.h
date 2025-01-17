#pragma once
#include "BiTree.h"


class Heap
{
protected:
	BiTree* arr;
	int max_size;
	int heap_size;
	int allocated;

	static int Left(int parent_index);
	static int Right(int parent_index);
	static int Parent(int child_index);
	void FixHeap(int node);
public:
	
	Heap(int max=1);
	Heap(BiTree arr[], int size);
	Heap(const Heap& origin) = delete;
	virtual ~Heap();
	void MakeEmpty();
	bool isEmpty();
	BiTree Min();
	BiTree DeleteMin();
	void Insert(BiTree& tree);
	const int getHeapSize()const {
		return heap_size;
	}

	Heap& operator=(const Heap& origin) = delete;
};

