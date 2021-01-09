#include "functions.h"

int main() {
	string path;
	ifstream file;
	cin >> path;
	file.open(path);
	if (!file.is_open())
	{
		cout << "File not found";
		exit(1);
	}
	SearchTree tree;
	try {
		tree = createTreeFromFile(file);
	}
	
	catch (const char* msg) {
		cout << "Error: " << msg << endl;
		exit(1);
	}

	file.close();
	
	BiTree hoffmanTree = buildHuffmanTree(tree);
	int fileWeight = 0;
	printHuffmanCode(hoffmanTree.root, fileWeight);
	cout << "Encoded file weight : " << fileWeight << " bits";
	tree.makeEmpty();
	hoffmanTree.makeEmpty();
	
}

