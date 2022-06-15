/* C++ program to check if a tree
is height-balanced or not */
#include <iostream>
#include <vector>
using namespace std;

/* A binary tree node has data,
pointer to left child and
a pointer to right child */
class node {
public:
	int data;
	node* left;
	node* right;
};

/* The function returns true if root is
balanced else false The second parameter
is to store the height of tree. Initially,
we need to pass a pointer to a location with
value as 0. We can also write a wrapper
over this function */
bool isBalanced(node* root, int* height)
{

	/* lh --> Height of left subtree
	rh --> Height of right subtree */
	int lh = 0, rh = 0;

	/* l will be true if left subtree is balanced
	and r will be true if right subtree is balanced */
	int l = 0, r = 0;

	if (root == NULL) {
		*height = 0;
		return 1;
	}

	/* Get the heights of left and right subtrees in lh and rh
	And store the returned values in l and r */
	l = isBalanced(root->left, &lh);
	r = isBalanced(root->right, &rh);

	/* Height of current node is max of heights of left and
	right subtrees plus 1*/
	*height = (lh > rh ? lh : rh) + 1;

	/* If difference between heights of left and right
	subtrees is more than 2 then this node is not balanced
	so return 0 */
    /* If this node is balanced and left and right subtrees
	are balanced then return true */
    return l && r && (abs(lh - rh) < 2);

    // if (abs(lh - rh) >= 2)
	// 	return 0;
	// else
	// 	return l && r;

}

/* UTILITY FUNCTIONS TO TEST isBalanced() FUNCTION */

/* Helper function that allocates a new node with the
given data and NULL left and right pointers. */
node* newNode(int data)
{
	node* Node = new node();
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
	node* root = newNode(1);
	root->left = newNode(2);
	root->right = newNode(3);
	root->left->left = newNode(4);
	root->left->right = newNode(5);
	root->right->left = newNode(6);
	root->left->left->left = newNode(7);

	if (isBalanced(root, &height))
		cout << "Tree is balanced";
	else
		cout << "Tree is not balanced";

	return 0;
}

// This is code is contributed by rathbhupendra
