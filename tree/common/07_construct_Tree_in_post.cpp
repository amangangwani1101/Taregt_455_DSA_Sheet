// Problem Link : https://leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/

// Problem Link : https://leetcode.com/problems/construct-binary-tree-from-postorder-and-inorder-traversal/

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

// Time complexity : O(NlogN) -- Average case | Worst Case -- O(N2) 
Node* constructBT(vector<int>&postOrder,vector<int>&inOrder,int &post_idx,int start,int end){
    if(start>end) return NULL;
    bool found = false;
    int idx = -1;
    for(int ptr=start;ptr<=end;ptr++){
        if(postOrder[post_idx]==inOrder[ptr]){
            found = true;
            idx = ptr;
            break;
        }
    }
    if(!found) return NULL;
    Node*root = new Node(postOrder[post_idx]);
    post_idx--;
    root->right = constructBT(postOrder,inOrder,post_idx,idx+1,end);
    root->left = constructBT(postOrder,inOrder,post_idx,start,idx-1);
    return root;
}

// optimize approach TC: O(N) | SC : O(N)
// using hashmap to save values of inorder array so that logN time required for searching element can be reduced

Node* constructTree(vector<int>&postOrder,vector<int>&inOrder,int postStart,int postEnd,int inStart,int inEnd,unordered_map<int,int>&mp){
    if(postStart<postEnd or inStart>inEnd)
        return NULL;
    
    int elem = mp[postOrder[postStart]];
    int reqElem = inEnd - elem;

    Node*root = new Node(postOrder[postStart]);

    root->left = constructTree(postOrder,inOrder,postStart-reqElem-1,postEnd,inStart,elem-1,mp);
    root->right = constructTree(postOrder,inOrder,postStart-1,postStart-reqElem,elem+1,inEnd,mp);

    return root;
}

Node* constructBTUtil(vector<int>&postOrder,vector<int>&inOrder){
    unordered_map<int,int>mp;
    for(int el=0;el<inOrder.size();el++){
        mp[inOrder[el]] = el; 
    }
    return constructTree(postOrder,inOrder,postOrder.size()-1,0,0,inOrder.size()-1,mp);
}

int main(){

    
    return 0;
}