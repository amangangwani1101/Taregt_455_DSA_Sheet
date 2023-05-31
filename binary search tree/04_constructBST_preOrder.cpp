#include<bits/stdc++.h>
using namespace std;

class Node{
public:
    int val;
    Node*left,*right;
    Node(){
        left = right = NULL;
    }
    Node(int data){
        val = data;
        left = right = NULL;
    }
};

class BST{
public:

    // construct bst from pre order
    Node* bstFromPreorderUtil(vector<int>&pre,int &idx,int left,int right){
        
        if(idx==pre.size()) 
            return NULL;
        
        if(!(pre[idx]>left and pre[idx]<right))
            return NULL;
        
        Node*root = new Node(pre[idx++]);
        root->left = bstFromPreorderUtil(pre,idx,left,root->val);
        root->right = bstFromPreorderUtil(pre,idx,root->val,right);
        return root;

    }
    Node* bstFromPreorder(vector<int>& preorder) {
        int idx=0;
        return bstFromPreorderUtil(preorder,idx,INT_MIN,INT_MAX);
    }
};
int main(){
    BST * obj = new BST();
    vector<int>ans;

    int prev = 0;
    Node *node = new Node(4);
    node->left = new Node(2);
    node->right = new Node(5);
    node->left->left = new Node(1);
    node->left->right = new Node(3);

    return 0;
}