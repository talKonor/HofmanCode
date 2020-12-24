#pragma once
#include "BiTree.h"


class Heap
{
private:
	BiTree* arr;
	int max_size;
	int heap_size;
	int allocated;
	static int Left(int parent_index);
	static int Right(int parent_index);
	static int Parent(int child_index);
	void FixHeap(int node);
public:
	Heap(int max);
	Heap(BiTree A[], int n);
	~Heap();
	BiTree Min();
	BiTree DeleteMin();
	void Insert(BiTree tree);
	const int getHeapSize()const {
		return heap_size;
	}





};

