#include "Heap.h"

int Heap::Left(int parent_index)
{
	return (2*parent_index+1);
}

int Heap::Right(int parent_index)
{
	return (2 * parent_index + 2);
}

int Heap::Parent(int child_index)
{
	return (child_index-1)/2;
}

void Swap(BiTree& first, BiTree& second) {
	BiTree temp = first;
	first = second;
	second = temp;
	temp.root = nullptr;
}

void Heap::FixHeap(int node)
{
	int min = node;
	int left = Left(node);
	int right = Right(node);
	if (left < heap_size && arr[left].root->data.getFreq() < arr[node].root->data.getFreq())
		min = left;
	if (right < heap_size && arr[right].root->data.getFreq() < arr[min].root->data.getFreq())
		min = right;

	if (min != node) {
		Swap(arr[node], arr[min]);
		FixHeap(min);
	}

}

Heap::Heap(int max)
{
	arr = new BiTree[max];
	max_size = max;
	heap_size = 0;
	allocated = 1;
}

Heap::Heap(BiTree A[], int n)
{
	heap_size = max_size = n;
	arr = A;

	allocated = 0;

	for (int i = n / 2 - 1; i >= 0; i--) {
		FixHeap(i);
	}
}

Heap::~Heap()
{
	if (allocated)
		delete[] arr;
	arr = nullptr;
}

void Heap::MakeEmpty()
{
	for (int i = 0; i < heap_size; i++) {
		arr[i].root = nullptr;
	}
	heap_size = 0;
}

bool Heap::isEmpty()
{
	return (heap_size==0);
}

BiTree Heap::Min()
{
	return arr[0];
}

BiTree Heap::DeleteMin()
{
	if (heap_size < 1)
		throw "ERROR";
	BiTree min = arr[0];
	heap_size--;
	arr[0] = arr[heap_size];
	FixHeap(0);
	return min;
}

void Heap::Insert(BiTree& tree)
{
	if (heap_size == max_size)
		throw "ERROR";
	int i = heap_size;
	heap_size++;
	while (i > 0 && arr[Parent(i)].root->data.getFreq() > tree.root->data.getFreq()) {
		arr[i] = arr[Parent(i)];
		i = Parent(i);
	}

	arr[i] = tree;
}
