#include "functions.h"


SearchTree& createTreeFromFile(ifstream& file) {
	SearchTree* tree = new SearchTree();
	char ch;
	while (file.get(ch)) {

		if (!file.good()) {
			throw "Couldn't read from file";
		}
		if (ch < 0 || ch > 127) {
			throw "Illegal character in file";
		}
		tree->insert(Node(ch)); // check if works for insert(ch)
	}

	return *tree;
}

void printHuffmanCode(BiTreeNode* t1, int& codeSize, string code) {
	if (t1 == nullptr)return;
	if (t1->left == nullptr && t1->right == nullptr) {
		if (t1->data.getChar() == '\n') {
			cout << "\\n" << ":" << code << endl;

		}
		else if (t1->data.getChar() == 9) {
			cout << "TAB" << ":" << code << endl;

		}
		else cout << t1->data.getChar() << ":" << code << endl;
		codeSize += (code.size()) * t1->data.getFreq();
		return;
	}
	else {
		printHuffmanCode(t1->left, codeSize, code.append("0"));
		code.pop_back();
		printHuffmanCode(t1->right, codeSize, code.append("1"));
	}
}

int buildArrFromTree(BiTree& tree, BiTree arr[])
{
	return insertNodeToArr(tree.root, arr);
}

int insertNodeToArr(BiTreeNode* root, BiTree arr[]) {
	int size;
	if (root == nullptr) {
		return 0;
	}
	else {
		BiTree newTree;
		size = insertNodeToArr(root->left, arr);
		newTree.root = new BiTreeNode(*root);
		newTree.root->left = nullptr;
		newTree.root->right = nullptr;
		arr[size] = newTree;
		size++;
		newTree.root = nullptr;
		size += insertNodeToArr(root->right, arr + size);
		return size;
	}
}

BiTree buildHuffmanTree(SearchTree& tree) {
	BiTree arr[ASSCII];
	int size = buildArrFromTree(tree, arr);
	huffmanHeap huffman(arr, size);
	return huffman.buildCodedTree();
}