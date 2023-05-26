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

vector<int>ans;

void KdistNodes(Node*root,int k){
    if(!root)
        return;
    if(!k){
        ans.push_back(root->val);
        return;
    }
    KdistNodes(root->left,k-1);
    KdistNodes(root->right,k-1);
}

bool nodeAtKDist(Node*root,int val,int k){
    if(!root) return false;
    if(root->val==val){
        KdistNodes(root,k);
        return true;
    }
    if(nodeAtKDist(root->left,val,k) or nodeAtKDist(root->right,val,k)){
        k-=1;
        if(!k) {
            ans.push_back(root->val);
            return false;
        }
        // KdistNodes(root->)
    }
}

int main(){

    int maxSum = INT_MIN;
    Node *node1 = new Node(1);
    Node *node2 = new Node(1);
    // Node*node[2] = new Node();
    node1->left = new Node(2);
    node1->right = new Node(-3);
    node1->left->left = new Node(4);
    node1->left->right = new Node(-5);

    // cout<<isIdenticalTree(node1,node2);
    return 0;
}