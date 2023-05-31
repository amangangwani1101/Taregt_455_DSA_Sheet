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

    // bst iterator , iterate bst and complete next() and hasNext() 
    // next():- means tell next element after current element 
    // hasNext() :- means do next exist
    Node*root,*currPtr=new Node();
    BST(){
        root = new Node();
        currPtr = NULL;
    }

    Node* inorderPreceder(Node*root,int val){
        Node*retPtr = NULL;
        while(root){
            if(root->val>val){
                retPtr = root;
                root = root->left;
            }
            else    
                root = root->right;
        }
        return retPtr;
    }

    int next(Node*root){
        if(!currPtr){
            Node*temp =root;
            while(temp->left)
                temp = temp->left;
            currPtr = temp;
            return currPtr->val;
        }
        currPtr = inorderPreceder(root,currPtr->val);
        return currPtr->val;
    }    
    bool hasNext(Node*root){
        if(!inorderPreceder(root,currPtr->val))
            return false;
        return true;
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