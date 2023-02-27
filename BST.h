#include <iostream>
#include "TreeNode.h"
using namespace std;

#ifndef MYBST
#define MYBST

class BST {
protected:
	BinaryNode* myRoot;

	void INORDERAUX(ostream& out, BinaryNode* subTreePointer) const;
	void PREORDERAUX(ostream& out, BinaryNode* subTreePointer) const;
	void POSTORDERAUX(ostream& out, BinaryNode* subTreePointer) const;
	void SHOWAUX(ostream& out, int mark, BinaryNode* subTreePointer) const;
	void SearchToDelete(const int& element, bool& Detect, BinaryNode*& LocalPointer, BinaryNode*& Parentpointer) const;

public:
	BST();
	bool Empty() const;
	void INORDER(ostream& out) const;
	void PREORDER(ostream& out) const;
	void POSTORDER(ostream& out) const;
	void SHOW(ostream& out) const;
	bool Search(const int& element) const;
	void Insert(const int& element);
	void Delete(const int& element);
};

#endif // !MYBST
