#include <iostream>
#include <vector>
using namespace std;
#define bool int

/* A binary tree node has data, pointer to left child
and a pointer to right child */
class Node
{
	public:
	int data;
	Node* left;
	Node* right;
};
/* UTILITY FUNCTIONS */
/* Helper function that allocates a new node with the
given data and NULL left and right pointers. */
Node* newNode(int data)
{
	Node* newNode = new Node();
	newNode->data = data;
	newNode->left = NULL;
	newNode->right = NULL;
	
	return newNode;
}
bool hasPathSum(Node* node, int sum){
	if(node == NULL){
		return false;
	}
	if (node->left == NULL && node->right == NULL){
		return sum == node->data;
	}
	sum = sum - node->data;
	return (hasPathSum(node->left,sum) || hasPathSum(node->right,sum));
}

int main()
{
	int sum = 21;
	/* Constructed binary tree is
			10
			/ \
			8 2
		   / \ /
		   3 5 2
	*/
	Node *root = newNode(10);
	root->left = newNode(8);
	root->right = newNode(2);
	root->left->left = newNode(3);
	root->left->right = newNode(5);
	root->right->left = newNode(2);

	if(hasPathSum(root, sum))
		cout << "There is a root-to-leaf path with sum " << sum;
	else
		cout << "There is no root-to-leaf path with sum " << sum;
	
	return 0;
}
