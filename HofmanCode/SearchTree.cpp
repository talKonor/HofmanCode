#include "SearchTree.h"

BinaryTree::BinaryTree():root(nullptr)
{  
}

BinaryTree::~BinaryTree()
{
}

bool BinaryTree::isEmpty()
{
    return (root==nullptr);
}

void BinaryTree::insert(Node item)
{
    BinaryTreeNode* temp = root;
    BinaryTreeNode* newNode;
    BinaryTreeNode* parent=nullptr;

    while (temp != nullptr) {
        parent = temp;
        if (item.getFreq() < temp->value.getFreq()) {
            temp = temp->left;
        }
        else {
            temp = temp->right;

        }
    }
    newNode = new BinaryTreeNode(item, nullptr, nullptr);
    if (parent == nullptr)
        root = newNode;
    else if (item.getFreq() < parent->value.getFreq()) {
        parent->left = newNode;
    }
    else {
        parent->right = newNode;
    }

}

BinaryTreeNode* BinaryTree::find(int key)
{
    BinaryTreeNode* temp = root;
    while (temp != nullptr) {
        if (temp->value.getFreq() == key)
            return temp;
        if (key < temp->value.getFreq())
            temp = temp->left;
        else
            temp = temp->right;
    }
    return nullptr;
}

void BinaryTree::Delete(int key)
{
    if(root!=nullptr){
        BinaryTreeNode* nodeToD = find(key);
        BinaryTreeNode* parent = root;
        BinaryTreeNode* temp = root;
        if (nodeToD != nullptr){
            while (temp != nullptr) {
                if (temp->left == nodeToD || temp->right == nodeToD) {
                    parent = temp;
                    break;
                }
                else if (key < temp->value.getFreq())
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
                while (temp->right!=nullptr){
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

BinaryTreeNode* BinaryTree::Min()
{
    BinaryTreeNode* temp = root;
    while (temp->left != nullptr) {
        temp = temp->left;
    }
    return temp;
}

BinaryTreeNode* BinaryTree::Max()
{
    BinaryTreeNode* temp = root;
    while (temp->right != nullptr) {
        temp = temp->right;
    }
    return temp;
}
