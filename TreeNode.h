#include<iostream>
using namespace std;

#ifndef BINNODE
#define BINNODE

class BinaryNode {
protected:
	int data;
	BinaryNode* right;
	BinaryNode* left;

public:
	friend class BST;
	BinaryNode();
	BinaryNode(int element);
	int getD() const;
	BinaryNode* getR() const;
	BinaryNode* getL() const;
	void setD(int element);
	void setR(BinaryNode* rightPointer);
	void setL(BinaryNode* leftPointer);
};

inline BinaryNode::BinaryNode()
	:right(NULL), left(NULL)
{}

inline BinaryNode::BinaryNode(int element)
	:data(element), right(NULL), left(NULL)
{}

inline int BinaryNode::getD() const {
	return data;
}

inline BinaryNode* BinaryNode::getR() const {
	return right;
}

inline BinaryNode* BinaryNode::getL() const {
	return left;
}

inline void BinaryNode::setD(int element) {
	this->data = element;
}

inline void BinaryNode::setR(BinaryNode* rightPointer) {
	this->right = rightPointer;
}

inline void BinaryNode::setL(BinaryNode* leftPointer) {
	this->left = leftPointer;
}
#endif // !BINNODE
