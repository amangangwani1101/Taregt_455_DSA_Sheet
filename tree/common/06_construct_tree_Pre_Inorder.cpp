// Problem Link : https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/

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
Node* constructBT(vector<int>&preOrder,vector<int>&inOrder,int &pre_idx,int start,int end){
    if(start>end) return NULL;
    bool found = false;
    int idx = -1;
    for(int ptr=start;ptr<end;ptr++){
        if(preOrder[pre_idx]==inOrder[ptr]){
            found = true;
            idx = ptr;
            break;
        }
    }
    if(!found) return NULL;
    Node*root = new Node(preOrder[pre_idx]);
    pre_idx++;
    root->left = constructBT(preOrder,inOrder,pre_idx,start,idx-1);
    root->right = constructBT(preOrder,inOrder,pre_idx,idx+1,end);
    return root;
}

// optimize approach TC: O(N) | SC : O(N)
// using hashmap to save values of inorder array so that logN time required for searching element can be reduced

Node* constructTree(vector<int>&preOrder,vector<int>&inOrder,int preStart,int preEnd,int inStart,int inEnd,unordered_map<int,int>&mp){
    if(preStart>preEnd or inStart>inEnd)
        return NULL;
    
    int elem = mp[preOrder[preStart]];
    int reqElem = elem - inStart;

    Node*root = new Node(preOrder[preStart]);

    root->left = constructTree(preOrder,inOrder,preStart+1,preStart+reqElem,inStart,elem-1,mp);
    root->right = constructTree(preOrder,inOrder,preStart+reqElem+1,preEnd,elem+1,inEnd,mp);

    return root;
}

Node* constructBTUtil(vector<int>&preOrder,vector<int>&inOrder){
    unordered_map<int,int>mp;
    for(int el=0;el<inOrder.size();el++){
        mp[inOrder[el]] = el; 
    }
    return constructTree(preOrder,inOrder,0,preOrder.size()-1,0,inOrder.size()-1,mp);
}

int main(){

    
    return 0;
}