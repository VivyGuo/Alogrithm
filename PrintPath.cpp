/* 
print the path 
from root to a given node in a binary tree 
*/
#include <iostream>
#include <vector>
using namespace std;

// structure of a node of binary tree
struct Node
{
	int data;
	Node *left, *right;
};

/* Helper function that allocates a new node with the
given data and NULL left and right pointers. */
struct Node* getNode(int data)
{
	struct Node *newNode = new Node;
	newNode->data = data;
	newNode->left = newNode->right = NULL;
	return newNode;
}
/*
    Method1- when find element , add element
*/
bool hasPath(Node *root, vector<int>& arr, int x)
{
	if (!root) {
		return false;
	}
	if(root->data == x){
		arr.insert(arr.begin(),root->data);
		return true;
   	}
  	if(hasPath(root->left,arr,x)|| hasPath(root->right,arr,x))
  	{
        arr.insert(arr.begin(),root->data);
    	return true;
  	}
  return false;		
}
/*
    Method2- first add, then remove 
bool hasPath(Node *root, vector<int>& arr, int x)
{
    // if root is NULL
    // there is no path
    if (!root)
        return false;
     
    // push the node's value in 'arr'
    arr.push_back(root->data);   
     
    // if it is the required node
    // return true
    if (root->data == x)   
        return true;
     
    // else check whether the required node lies
    // in the left subtree or right subtree of
    // the current node
    if (hasPath(root->left, arr, x) ||
        hasPath(root->right, arr, x))
        return true;
     
    // required node does not lie either in the
    // left or right subtree of the current node
    // Thus, remove current node's value from
    // 'arr'and then return false   
    arr.pop_back();
    return false;           
}
*/
// function to print the path from root to the
// given node if the node lies in the binary tree
void printPath(Node *root, int x)
{
	// vector to store the path
	vector<int> arr;
	
	// if required node 'x' is present
	// then print the path
	if (hasPath(root, arr, x))
	{
		for (int i=0; i<arr.size()-1; i++)
			cout << arr[i] << "->";
		cout << arr[arr.size() - 1];
	}
	else // 'x' is not present in the binary tree
		cout << "No Path";
}
int main()
{
	// binary tree formation
	struct Node *root = getNode(1);
	root->left = getNode(2);
	root->right = getNode(3);
	root->left->left = getNode(4);
	root->left->right = getNode(5);
	root->left->right->right = getNode(11);
	root->right->left = getNode(6);
	root->right->right = getNode(7);
		
	int x = 11;
	printPath(root, x);
	return 0;
}