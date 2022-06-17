
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
vector<int> postorder(Node *root) {
    vector<int> res;
    if (root == nullptr) {
        return res;
    }

    stack<Node *> stk;
    Node *prev,*cur = nullptr;
    while (root != nullptr || !stk.empty()) {
        // postorder(node->left) 左
        while (root != nullptr) {
            stk.emplace(root);
            root = root->left;
        }
        cur = stk.top();
        stk.pop();
        //无右子树 或右子树已遍历完，输出root，完成：左->右->根 
        if (cur->right == nullptr || cur->right == prev) {
            res.emplace_back(cur->data); // print node 根
            prev = cur; //记录已访问节点用于回溯到父节点时判断是否已遍历
            root = nullptr;  //继续pop
        } else { // postorder(node->right) 右
            stk.emplace(cur); // 右子树有值，将弹出的root再push到栈
            root = cur->right;
        }
    }
    return res;
}

int main(){
    /* Constructed binary tree is
              1
            /   \
            2    3
                /  \
               4     5
    */
    struct Node *root = new Node(1);
    root->left        = new Node(2);
    root->right       = new Node(3);
    root->right->left  = new Node(4);
    root->right->right = new Node(5);
    postorder(root);
    return 0;
}