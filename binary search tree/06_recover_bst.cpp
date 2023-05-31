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

// recover a bst 2nodes are swapped from their position so now recover original bst
// if 2 nodes are swapped in sorted inorder BST then 2 case arrises
//  either swapping is adjacent
// example : [1,2,3,4,6,5,7,8,9]
// here first = 6,middle = 5 , last = Null means adjacent swaps

// else swapping is not adjacent
// example : [1,2,3,8,5,6,7,4,9]
// here first = 8,middle = 5 , last = 4 means not adjacent swaps

class BST{
public:
    void recoverBST(Node*root,Node*&prev,Node*&first,Node*&middle,Node*&last)
    {
        if(!root) return;
        recoverBST(root->left,prev,first,middle,last);
        
        // just little optimization
        if(first and last) return;

        if(prev and prev->val>root->val){
            if(!first) first = prev,middle = root;
            else last = root;
        }
        prev = root;
        
        recoverBST(root->right,prev,first,middle,last);
    }
};


int main(){
    BST * obj = new BST();
    vector<int>ans;

    Node *node = new Node(4);
    node->left = new Node(2);
    node->right = new Node(5);
    node->left->left = new Node(1);
    node->left->right = new Node(3);

    Node*f=NULL,*m=NULL,*l=NULL,*prev=NULL;
    obj->recoverBST(node,prev,f,m,l);
    if(f and l) swap(f->val,l->val);
    else swap(f->val,m->val);
    return 0;
}