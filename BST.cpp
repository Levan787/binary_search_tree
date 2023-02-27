#include<iostream>
#include <iomanip>
#include "BST.h"
#include "TreeNode.h"
using namespace std;

BST::BST()
	:myRoot(NULL)
{}

bool BST::Empty() const {
	return myRoot == NULL;
}

void BST::INORDER(ostream& out) const {
	INORDERAUX(out, myRoot);
}

void BST::INORDERAUX(ostream& out, BinaryNode* SUBTREEROOT) const {
	if (SUBTREEROOT != NULL) {
		INORDERAUX(out, SUBTREEROOT->getL());  // Left operation
		out << SUBTREEROOT->getD() << " ";    // V_Data operation
		INORDERAUX(out, SUBTREEROOT->getR());   // Right operation
	}
}

void BST::PREORDER(ostream& out) const {
	PREORDERAUX(out, myRoot);
}

void BST::PREORDERAUX(ostream& out, BinaryNode* SUBTREEROOT) const {
	if (SUBTREEROOT != NULL) {
		out << SUBTREEROOT->getD() << " ";  // V_Data operation
		PREORDERAUX(out, SUBTREEROOT->getL()); // Left operation
		PREORDERAUX(out, SUBTREEROOT->getR());  // Right operation
	}
}

void BST::POSTORDER(ostream& out) const {
	POSTORDERAUX(out, myRoot);
}

void BST::POSTORDERAUX(ostream& out, BinaryNode* SUBTREEROOT) const {
	if (SUBTREEROOT != NULL) {
		POSTORDERAUX(out, SUBTREEROOT->getL()); // LEFT operation
		POSTORDERAUX(out, SUBTREEROOT->getR());  // RIGHT operation
		out << SUBTREEROOT->getD() << " ";  // V_DATA operation
	}
}

void BST::SHOW(ostream& out) const {
	SHOWAUX(out, 0, myRoot);
}

void BST::SHOWAUX(ostream& out, int mark, BinaryNode* SUBTREEROOT) const {
	if (SUBTREEROOT != NULL) {
		SHOWAUX(out, mark + 8, SUBTREEROOT->getR());
		out << setw(mark) << " " << SUBTREEROOT->getD() << endl;
		SHOWAUX(out, mark + 8, SUBTREEROOT->getL());
	}
}

bool BST::Search(const int& Element) const {
	BinaryNode* LocalPointer = myRoot;
	bool Detect = false;

	while (!Detect && LocalPointer!=NULL){
		if (Element < LocalPointer->getD())   // plunge left
			LocalPointer = LocalPointer->getL();
		else if (Element > LocalPointer->getD())   // plunge right
			LocalPointer = LocalPointer->getR();
		else
			Detect = true;  // Element is Detect
	}

	return Detect;
}

void BST::Insert(const int& Element) {
	BinaryNode* LocalPointer = myRoot,   // seek pointer
		*Parentpointer = NULL;   // on going node of pointer to parent
	bool Detect = false;  // indicates if Element is already in BST

	while (!Detect && LocalPointer != NULL) {
		Parentpointer = LocalPointer;
		if (Element < LocalPointer->getD())   // plunge left
			LocalPointer = LocalPointer->getL();
		else if (Element > LocalPointer->getD())   // plunge right
			LocalPointer = LocalPointer->getR();
		else
			Detect = true;  // Element is Detect
	}

	if (!Detect) {
		LocalPointer = new BinaryNode(Element);  // it should construct new node

		if (Parentpointer == NULL) // tree is clear
			myRoot = LocalPointer;
		else if (Element < Parentpointer->getD())   // it should put left of parent
			Parentpointer->setL(LocalPointer);
		else
			Parentpointer->setR(LocalPointer);  // it should put right of parent
	}
	else
		cout << "\nElement is in the tree" << endl;
}

void BST::SearchToDelete(const int& Element, bool& Detect, BinaryNode*& LocalPointer, BinaryNode*& Parentpointer) const {
	LocalPointer = myRoot;
	Parentpointer = NULL;
	Detect = false;

	while (!Detect && LocalPointer != NULL) {
		if (Element < LocalPointer->getD()) {   // plunge left
			Parentpointer = LocalPointer;
			LocalPointer = LocalPointer->getL();
		}
		else if (Element > LocalPointer->getD()) {  // plunge right
			Parentpointer = LocalPointer;
			LocalPointer = LocalPointer->getR();
		}
		else
			Detect = true;  // Element is Detect
	}
}

void BST::Delete(const int& Element) {
	bool Detect;
	BinaryNode* x,   // it points node to be deleted
		* Parentpointer;  // it points to node parent: x and xSucc

	SearchToDelete(Element, Detect, x, Parentpointer);

	if (!Detect) {
		cout << "Element is not in BST" << endl;
		return;
	}

	if (x->getL() != NULL && x->getR() != NULL) { // node should have two children
		BinaryNode* xSucc = x->getR();
		Parentpointer = x;

		while (xSucc->getL() != NULL) {  // plunge left
			Parentpointer = xSucc;
			xSucc = xSucc->getL();
		}

		// it should move capacity of xSucc to x
		x->setD(xSucc->getD());
		x = xSucc;
	}

	// node should have 0 or 1 child
	BinaryNode* subTreePointer = x->getL();
	if (subTreePointer == NULL)
		subTreePointer = x->getR();

	if (Parentpointer == NULL) // root being Deleted
		myRoot = subTreePointer;
	else if (Parentpointer->getL() == x)
		Parentpointer->setL(subTreePointer);
	Parentpointer->setR(subTreePointer);

	delete x;
}
