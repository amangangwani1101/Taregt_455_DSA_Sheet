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


// clean code 
class NodeValue{
    public:
    int maxSize;
    int minNode;
    int maxNode;
    NodeValue(int size,int mini,int maxi){
        minNode = mini;
        maxNode = maxi;
        maxSize = size;
    }
};


class BST{
public:
    pair<pair<bool,int>,pair<int,int>> largestBSTUtil(Node*root,int &size){

        if(!root) return{{true,0},{INT_MAX,INT_MIN}};

        pair<pair<bool,int>,pair<int,int>> left = largestBSTUtil(root->left,size);
        pair<pair<bool,int>,pair<int,int>> right = largestBSTUtil(root->right,size);
        bool bst = false;
        if(left.first.first and right.first.first and 
        root->val>left.second.second and root->val<right.second.first){
            size = max(size,left.first.second+right.first.second+1);
            bst = true;
        }
        int mini = min({root->val,left.second.first,right.second.first});
        int maxi = max({root->val,left.second.second,right.second.second});
        return {{bst,left.first.second+right.first.second+1},{mini,maxi}};
    }

    NodeValue largeBSTClean(Node*root){
        if(!root) return NodeValue(0,INT_MAX,INT_MIN);
        NodeValue left  = largeBSTClean(root->left);
        NodeValue right  = largeBSTClean(root->right);

        if(root->val>left.maxNode and root->val<right.minNode){
            return NodeValue(left.maxSize+right.maxSize+1,min(root->val,left.minNode),max(root->val,right.maxNode));
        }
        return NodeValue(max(left.maxSize,right.maxSize),INT_MIN,INT_MAX);
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

    return 0;
}