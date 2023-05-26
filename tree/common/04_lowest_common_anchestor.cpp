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

Node* lowestCommonAncestor(Node* root, Node* p, Node* q) {
        if(!root)
            return NULL;
        if(root==p or root==q) return root;
        Node*left = lowestCommonAncestor(root->left,p,q);
        Node*right = lowestCommonAncestor(root->right,p,q);
        if(left and right)
            return root;
        return left?left:right;
    }

int main(){

    Node *node = new Node(1);
    node->left = new Node(2);
    node->right = new Node(-3);
    node->left->left = new Node(4);
    node->left->right = new Node(-5);

    cout<<lowestCommonAncestor(node,node->left,node->right);

    return 0;
}