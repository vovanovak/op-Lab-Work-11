#include <iostream>

static int i = 1;

struct TreeNode {
	TreeNode* left;
	TreeNode* right;
	double value;
	

	TreeNode();

	TreeNode(TreeNode* left, TreeNode* right, double value);

	bool isLeaf();

	double count();
	
	void postorder(TreeNode* p, int indent = 0);

	int get_max_leaf_height(TreeNode* n, int height = 1);
	void print(int max_height, int indent, int y, int max);

	void set_cursor_normal(int height);
};