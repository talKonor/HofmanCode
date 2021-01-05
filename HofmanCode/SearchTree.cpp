#include "SearchTree.h"

SearchTree::SearchTree()
{
}

SearchTree::~SearchTree()
{
}



void SearchTree::insert(Node item)
{
	BiTreeNode* temp = root;
	BiTreeNode* newNode;
	BiTreeNode* parent = nullptr;

	while (temp != nullptr) {
		parent = temp;
		if (temp->data.getChar() == item.getChar()) {
			temp->data.addFreq(1); //enum
			return;
		}
		if (item.getChar() < temp->data.getChar()) {
			temp = temp->left;
		}
		else {
			temp = temp->right;

		}
	}
	newNode = new BiTreeNode(item, nullptr, nullptr);
	if (parent == nullptr)
		root = newNode;
	else if (item.getChar() < parent->data.getChar()) {
		parent->left = newNode;
	}
	else {
		parent->right = newNode;
	}

}

BiTreeNode* SearchTree::find(char key)
{
	BiTreeNode* temp = root;
	while (temp != nullptr) {
		if (temp->data.getChar() == key)
			return temp;
		if (key < temp->data.getChar())
			temp = temp->left;
		else
			temp = temp->right;
	}
	return nullptr;
}

void SearchTree::Delete(char key)
{
	if (root != nullptr) {
		BiTreeNode* nodeToD = find(key);
		BiTreeNode* parent = root;
		BiTreeNode* temp = root;
		if (nodeToD != nullptr) {
			while (temp != nullptr) {
				if (temp->left == nodeToD || temp->right == nodeToD) {
					parent = temp;
					break;
				}
				else if (key < temp->data.getChar())
					temp = temp->left;
				else
					temp = temp->right;
			}
			if (!(nodeToD->left != nullptr && nodeToD->right != nullptr)) {
				parent->left = nodeToD->left;
				parent->right = nodeToD->right;
				nodeToD->left = nullptr;
				nodeToD->right = nullptr;
				delete nodeToD;
			}
			else {
				temp = nodeToD->left;
				while (temp->right != nullptr) {
					parent = temp;
					temp = temp->right;
				}
				nodeToD = temp;
				parent->right = temp->left;
				temp->left = nullptr;
				delete temp;
			}
		}
	}
}

BiTreeNode* SearchTree::Min()
{
	BiTreeNode* temp = root;
	while (temp->left != nullptr) {
		temp = temp->left;
	}
	return temp;
}

BiTreeNode* SearchTree::Max()
{
	BiTreeNode* temp = root;
	while (temp->right != nullptr) {
		temp = temp->right;
	}
	return temp;
}
