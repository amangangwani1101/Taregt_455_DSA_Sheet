// Problem Link : https://practice.geeksforgeeks.org/problems/boundary-traversal-of-binary-tree/0

// Problem Link : https://leetcode.com/problems/serialize-and-deserialize-binary-tree/

//Problem Link : https://practice.geeksforgeeks.org/problems/count-number-of-nodes-in-a-binary-tree/1

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


void leftBoundary(Node*root,vector<int>&ans){
    if(!root) return ;
    if(root->left){
        ans.push_back(root->val);
        leftBoundary(root->left,ans);
    }
    else if(root->right){
        ans.push_back(root->val);
        leftBoundary(root->right,ans);
    }

    return;
}

void leafNode(Node*root,vector<int>&ans){
    if(!root) return;
    leafNode(root->left,ans);
    leafNode(root->right,ans);
    if(!root->left and !root->right)
        ans.push_back(root->val);
    return;
}

void rightBoundary(Node*root,vector<int>&ans){
    if(!root) return ;
    if(root->right){
        rightBoundary(root->right,ans);
        ans.push_back(root->val);
    }
    else if(root->left){
        rightBoundary(root->left,ans);
        ans.push_back(root->val);
    }

    return;
}


vector<int> boundaryTraversalBT(Node*root){
    
    vector<int>ans;

    ans.push_back(root->val);

    leftBoundary(root->left,ans);

    // leaf nodes
    leafNode(root->left,ans);
    leafNode(root->right,ans);

    // right boundary
    rightBoundary(root->right,ans);
    
    return ans;
}
int main(){

    Node *node1 = new Node(1);
    node1->left = new Node(2);
    node1->right = new Node(-3);
    node1->left->left = new Node(4);
    node1->left->right = new Node(-5);

    boundaryTraversalBT(node1);
    
    return 0;
}