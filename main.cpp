#include<iostream>
#include "BST.h"
using namespace std;

int main() {
	BST BST;
	// test free function
	cout << "BST is building. Is it empty or Not? " << boolalpha << BST.Empty() << endl;

	// test inclusion of function
	cout << "Enter integer into true BST. \nTry items not in the BST and some that are in it: " << endl;
	int Num;
	while (true) {
		cout << "Here is Element to insert (-888 to stop inclusion) : ";
		cin >> Num;
		if (Num == -888)
			break;
		BST.Insert(Num);
	}

	cout << "Is BST empty or Not? " << boolalpha << BST.Empty() << endl;

	BST.SHOW(cout);   // testing SHOW
	cout << "\nPREORDER negation : " << endl;
	BST.PREORDER(cout);   // testing PREORDER
	cout << "\nINORDER negation : " << endl;
	BST.INORDER(cout);   // testing INORDER
	cout << "\nPOSTORDER negation : " << endl;
	BST.POSTORDER(cout);  // testing POSTORDER


	cout << "\n\nTry to explore some elements that is not in the BST and also both elements which are in it : " << endl;
	while (true) {
		cout << "Item to explore (-888 to stop inclusion) : ";
		cin >> Num;
		if (Num == -888)
			break;
		cout << Num << (BST.Search(Num) ? "is found" : "is not found") << endl;
	}


	cout << "Try to explore some elements that is not in the BST and also both elements which are in it : " << endl;
	while (true) {
		cout << "Item to delete (-888 to stop inclusion) : ";
		cin >> Num;
		if (Num == -888)
			break;
		BST.Delete(Num);
		BST.SHOW(cout);
	}
	cout << "PREORDER negation : " << endl;
	BST.PREORDER(cout);

}
