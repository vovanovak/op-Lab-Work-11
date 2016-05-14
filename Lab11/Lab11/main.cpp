#include <iostream>
#include "TreeNode.h"
using namespace std;

int a, b, c, d;

void input_of_number(int &a);
void init_tree(TreeNode*& tree);
void init_numbers();

void main(){
	cout << "Lab11" << endl;
	cout << "((a + b) * c - d)" << endl;

	
	init_numbers();

	
	TreeNode* tree = new TreeNode();
	init_tree(tree);

	cout << "Total result: " << tree->count() << endl;
}

void input_of_number(int &a) {
	cin >> a;

	while (cin.fail()) {
		cout << "Enter proper number!" << endl;
		cin.clear();
		cin.ignore(256, '\n');
		cin >> a;
	}
}

void init_tree(TreeNode*& tree){
	tree->value = '-';
	TreeNode* aPlusB = new TreeNode(new TreeNode(nullptr, nullptr, a), new TreeNode(nullptr, nullptr, b), '+');
	TreeNode* aPlusBMultiplyC = new TreeNode(aPlusB, new TreeNode(nullptr, nullptr, c), '*');
	tree->left = aPlusBMultiplyC;
	tree->right = new TreeNode(nullptr, nullptr, d);
	
}

void init_numbers(){
	cout << "Enter a: ";
	input_of_number(a);

	cout << "Enter b: ";
	input_of_number(b);

	cout << "Enter c: ";
	input_of_number(c);

	cout << "Enter d: ";
	input_of_number(d);
}