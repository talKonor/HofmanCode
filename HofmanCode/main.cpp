#include "functions.h"
/// <summary>
///Hello dear user!
/// This program generates a huffman code for a text file.
/// If you wish the compress your story or text insert the path of the file.
/// The program will print to the screen every letter with its corresponding code.
/// then the program will print the size of the huffman 
/// tree in bits(each letters code times its frequency) 
/// Thank for choosing to compress with us and have an nice day!
/// </summary>

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

