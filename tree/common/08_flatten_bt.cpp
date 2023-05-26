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


void flattenBT(Node*root){
    if(!root)
        return;
    
    Node*save = root->right;
    Node*temp = root;
    temp->right = temp->left;
    temp->left = NULL;
    while(temp->right){
        temp = temp->right;
    }
    temp->right = save;
    flattenBT(root->right);
}

int main(){

    Node *node1 = new Node(1);
    node1->left = new Node(2);
    node1->right = new Node(-3);
    node1->left->left = new Node(4);
    node1->left->right = new Node(-5);

    flattenBT(node1);
    
    return 0;
}