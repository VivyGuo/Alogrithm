#include <iostream>
#include <stack>
#include <vector>
using namespace std;
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    Node (int data){
        this->data = data;
        left = right = NULL;
    }
};
/* Iterative function for preorder tree traversal */
void preOrder(struct Node *root){
    stack<Node *> s;
    Node *curr = root;
    while (curr != NULL || s.empty() == false)
    {
        //visit left subtree
        while (curr !=  NULL){
            //print root node
            cout << curr->data << " ";
            
            s.push(curr);
            curr = curr->left;
        }
        /* Current must be NULL at this point */
        curr = s.top();//pop node
        s.pop();
        //visit right subtree
        curr = curr->right;
    }
} 
/* Iterative function for inorder tree traversal */
void inOrder(struct Node *root){
    stack<Node *> s;
    Node *curr = root;
    while (curr != NULL || s.empty() == false)
    {
        /* Reach the left most Node of the curr Node */
        while (curr !=  NULL)
        {
            /* place pointer to a tree node on the stack before traversing
              the node's left subtree */
            s.push(curr);
            curr = curr->left;
        }
        /* Current must be NULL at this point */
        curr = s.top();
        s.pop();
        cout << curr->data << " ";
        /* we have visited the node and its left subtree.  Now, it's right
           subtree's turn */
        curr = curr->right;
    } /* end of while */
} 
int main(){
    /* Constructed binary tree is
              1
            /   \
          2      3
        /  \
      4     5*/
    struct Node *root = new Node(1);
    root->left        = new Node(2);
    root->right       = new Node(3);
    root->left->left  = new Node(4);
    root->left->right = new Node(5);
    inOrder(root);
    return 0;
}
