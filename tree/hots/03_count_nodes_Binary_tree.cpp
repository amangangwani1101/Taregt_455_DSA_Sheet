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
// optimized approach : Time Complexity O(log^2(N))
// approach : For A Complete Binary Tree If Level of tree is 3 and completely filed then number of nodes in tree => 2^l-1
// now in complete inary tree there is possibility that last level is not completly filled then in such case leftHeight!=rightHeight then recursively  go to left and right of tree , if at any point leftHeight = rightHeight then we know our answer for taht subtree is 2^leftHeght-1

int getHeightLeftTree(Node*root){
    int length=0;
    while(root){
        length++;
        root = root->left;
    }
    return length;
}

int getHeightRightTree(Node*root){
    int length=0;
    while(root){
        length++;
        root = root->right;
    }
    return length;
}

int countNodesCompleteBinaryTree(Node*root){
    int lh = getHeightLeftTree(root);
    int rh = getHeightRightTree(root);

    if(lh==rh) return (1<<lh)-1;

    int cntNodesLeft = countNodesCompleteBinaryTree(root->left);
    int cntNodesRight = countNodesCompleteBinaryTree(root->right);

    return 1 + cntNodesLeft + cntNodesRight;
}

int main(){

    Node *node1 = new Node(1);
    node1->left = new Node(2);
    node1->right = new Node(-3);
    node1->left->left = new Node(4);
    node1->left->right = new Node(-5);

    cout<<countNodesCompleteBinaryTree(node1);
    return 0;
}