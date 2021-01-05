#include "FileManager.h"

int main() {
	string path;
	ifstream file;
	cin >> path;
		file.open(path);
		if (!file.is_open())
		{
			cout << "File not found";
			return 0;
		}
	SearchTree tree = createTreeFromFile(file);
	HoffmanHeap hoffman(tree);
	BiTree hoffmanTree = hoffman.buildCodedTree();
	int fileWeight = 0;
	printTree(hoffmanTree.root, fileWeight);
	cout << "Encoded file weight : " <<	fileWeight <<"bits";
	file.close();
}


SearchTree& createTreeFromFile(ifstream& file) {
	SearchTree* tree = new SearchTree();
	char ch;
	while (file.get(ch)) {	
		tree->insert(Node(ch)); // check if works for insert(ch)
	}
	return *tree;
}


void insertToheap(Heap& h1, BiTreeNode* t1) {
	if (t1 == nullptr)
		return;
	else
	{
		BiTree temp(t1);
		insertToheap(h1, t1->left);
		h1.Insert(temp);
		insertToheap(h1, t1->right);
		t1->left = nullptr;
		t1->right = nullptr;
		return;
	}
}

void printTree(BiTreeNode* t1, int& codeSize, string code) {
	if (t1 == nullptr)return;
	if (t1->left == nullptr && t1->right == nullptr) {
		if (t1->data.getChar() == '\n') {
			cout << "\\n"<< ":" << code << endl;

		}
		else cout << t1->data.getChar() << ":" << code << endl;
		codeSize += (code.size()) * t1->data.getFreq() ;
		return;
	}
	else {
		printTree(t1->left,codeSize,code.append("0"));
		code.pop_back();
		printTree(t1->right,codeSize,code.append("1"));
	}
}