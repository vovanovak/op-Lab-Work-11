#include <iostream>

static int i = 1;

struct TreeNode {
	TreeNode* left;
	TreeNode* right;
	double value;
	

	TreeNode(){
		left = nullptr;
		right = nullptr;
		value = -1;
	}

	TreeNode(TreeNode* left, TreeNode* right, double value){
		this->left = left;
		this->right = right;
		this->value = value;
	}

	bool isLeaf(){
		if (left != nullptr && right != nullptr){
			return false;
		}
		else {
			return true;
		}
	}

	double count(){
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
};