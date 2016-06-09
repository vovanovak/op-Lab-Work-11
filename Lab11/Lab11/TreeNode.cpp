#include "TreeNode.h"
#include <iomanip>
#include <windows.h>

using namespace std;

TreeNode::TreeNode(){
	left = nullptr;
	right = nullptr;
	value = -1;
}

TreeNode::TreeNode(TreeNode* left, TreeNode* right, double value){
	this->left = left;
	this->right = right;
	this->value = value;
}

bool TreeNode::isLeaf(){
	if (left != nullptr && right != nullptr){
		return false;
	}
	else {
		return true;
	}
}

void TreeNode::postorder(TreeNode* p, int indent)
{
	if (p != NULL) {
		if (p->right) {
			postorder(p->right, indent + 4);
		}
		if (indent) {
			
			std::cout << std::setw(indent) << ' ';
		}
		if (p->right) std::cout << " /\n" << std::setw(indent) << ' ';
		
		if (p->isLeaf())
			std::cout << p->value << "\n ";
		else 
			std::cout << (char)p->value << "\n ";
		if (p->left) {
			std::cout << std::setw(indent) << ' ' << " \\\n";
			postorder(p->left, indent + 4);
		}
	}
}

double TreeNode::count(){
	if (isLeaf()){
		return value;
	}
	else {


		double countLeft = left->count();
		double countRight = right->count();
		double res;
		char operation = (char)value;
		switch (operation){
		case '+':
			res = countLeft + countRight;
			break;
		case '-':
			res = countLeft - countRight;
			break;
		case '*':
			res = countLeft * countRight;
			break;
		case '/':
			res = countLeft / countRight;
			break;
		}

		std::cout << "y" << i << ": " << res << std::endl;
		i++;

		return res;
	}

	
}

int TreeNode::get_max_leaf_height(TreeNode* n, int height){
	if (n->left == NULL && n->right == NULL){
		return height - 1;
	}
	else {
		int left = get_max_leaf_height(n->left, height + 1);
		int right = get_max_leaf_height(n->right, height + 1);

		return (left > right) ? left: right;
	}
}

void TreeNode::set_cursor_normal(int height){
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD coord;
	coord.X = 0;
	coord.Y = (height + 4) * 3;
	SetConsoleCursorPosition(handle, coord);
}

void TreeNode::print(int height, int indent, int y, int init_height){
	int nodeHalfIndent = 3;
	int numberOfIndents = nodeHalfIndent * (height + 1);

	CONSOLE_SCREEN_BUFFER_INFO SBInfo;
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	GetConsoleScreenBufferInfo(handle, &SBInfo);

	COORD coord;
	coord.X = indent + 2 * numberOfIndents - 1;
	if (y == 0)
		coord.Y = SBInfo.dwCursorPosition.Y;
	else
		coord.Y = y;

	int temp_y = SBInfo.dwCursorPosition.Y;

	SetConsoleCursorPosition(handle, coord);

	if (this->left == NULL && this->right == NULL)
		cout << this->value << endl;
	else
		cout << (char)this->value << endl;

	coord.X = indent + 2 * numberOfIndents - 1;
	coord.Y += 1;

	SetConsoleCursorPosition(handle, coord);

	if (!(this->left == NULL && this->right == NULL))
		cout << "|" << endl;

	coord.X = indent + numberOfIndents - 1;
	coord.Y += 1;

	SetConsoleCursorPosition(handle, coord);

	if (!(this->left == NULL && this->right == NULL)){
		coord.X = 2 * nodeHalfIndent * height - init_height + height;

		SetConsoleCursorPosition(handle, coord);
		cout << setfill('-') << setw(nodeHalfIndent * 5 - 1);
	}
	
	cout << "\n";
	
	if (left != NULL)
		left->print(height - 1, indent - 1, 0, init_height);
	
	if (right != NULL)
		right->print(height - 1, indent + nodeHalfIndent * 4, temp_y + 3, init_height);
	
}