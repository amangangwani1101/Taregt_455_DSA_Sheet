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

int maxPathSumtree(Node*root,int&maxSum){
    if(!root) return 0;
    int left = maxPathSumtree(root->left,maxSum);
    int right = maxPathSumtree(root->right,maxSum);
    maxSum = max({maxSum,root->val,left+root->val,right+root->val,left+right+root->val});
    return max({root->val,left+root->val,right+root->val});
}

int main(){

    int maxSum = INT_MIN;
    Node *node = new Node(1);
    node->left = new Node(2);
    node->right = new Node(-3);
    node->left->left = new Node(4);
    node->left->right = new Node(-5);

    cout<<maxPathSumtree(node,maxSum);
    return 0;
}