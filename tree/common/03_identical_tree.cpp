#include<bits/stdc++.h>
using namespace std;

class Node{
public:
    int val;
    Node*left,*right;
    Node(int data){
        val = data;
        left = right = NULL;
    }
};

bool isIdenticalTree(Node*root1,Node*root2){
    if(!root1 and !root2)
        return true;
    if(!root1 or !root2 or root1->val!=root2->val)
        return false;
    bool left = isIdenticalTree(root1->left,root2->left);
    bool right = isIdenticalTree(root1->right,root2->right);
    return left && right;
}

int main(){

    int maxSum = INT_MIN;
    Node *node1 = new Node(1);
    Node *node2 = new Node(1);
    // Node*node[2] = new Node();
    node1->left = new Node(2);
    node1->right = new Node(-3);
    node1->left->left = new Node(4);
    node1->left->right = new Node(-5);

    cout<<isIdenticalTree(node1,node2);
    return 0;
}