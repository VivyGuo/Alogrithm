/* C++ program to check if a tree
is height-balanced or not */
#include <iostream>
#include <vector>
using namespace std;

/* A binary tree node has data,
pointer to left child and
a pointer to right child */
class TreeNode {
public:
	int data;
	TreeNode* left;
	TreeNode* right;
};

/* The function returns true if root is
balanced else false The second parameter
is to store the height of tree. Initially,
we need to pass a pointer to a location with
value as 0. We can also write a wrapper
over this function */
int height(TreeNode* node) {
    if (node == NULL) {
        return 0;
    }
    int leftHeight = height(node->left);
    int rightHeight = height(node->right);
    if (leftHeight == -1 || rightHeight == -1 || abs(leftHeight - rightHeight) > 1) {
        return -1;
    } else {
        return max(leftHeight, rightHeight) + 1;
    }
}

bool isBalanced(TreeNode* node) {
    return height(node) >= 0;
}

/* UTILITY FUNCTIONS TO TEST isBalanced() FUNCTION */

/* Helper function that allocates a new node with the
given data and NULL left and right pointers. */
TreeNode* newNode(int data)
{
	TreeNode* Node = new TreeNode();
	Node->data = data;
	Node->left = NULL;
	Node->right = NULL;

	return (Node);
}

// Driver code
int main()
{
	int height = 0;

	/* Constructed binary tree is
			1
			/ \
			2 3
			/ \ /
			4 5 6
			/
			7
	*/
	TreeNode* root = newNode(1);
	root->left = newNode(2);
	root->right = newNode(3);
	root->left->left = newNode(4);
	root->left->right = newNode(5);
	root->right->left = newNode(6);
	root->left->left->left = newNode(7);

	if (isBalanced(root))
		cout << "Tree is balanced";
	else
		cout << "Tree is not balanced";

	return 0;
}

// This is code is contributed by rathbhupendra
