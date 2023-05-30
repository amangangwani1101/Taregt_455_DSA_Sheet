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


void getDiameter(Node*root,int level,int &minOff,int &maxOff){
    if(!root) return;
    minOff = min(minOff,level);
    maxOff = max(maxOff,level);
    getDiameter(root->left,level-1,minOff,maxOff);
    getDiameter(root->right,level+1,minOff,maxOff);
    return ;
}

vector<vector<int>> verticalTraversal(Node*root){
    int minOff = INT_MAX,maxOff=INT_MIN;
    getDiameter(root,0,minOff,maxOff);
    vector<vector<int>>ans(maxOff-minOff+1);
    queue<pair<Node*,int>>q;
    q.push({root,0});
    while(!q.empty()){
        int sz = q.size();
        vector<vector<int>>temp(maxOff-minOff+1);
        while(sz--){
            Node* el = q.front().first;
            int level = q.front().second;
            q.pop();
            temp[level+abs(minOff)].push_back(el->val);
            if(el->left)
                q.push({el->left,level-1});
            if(el->right)
                q.push({el->right,level+1});
        }
        for(int i=0;i<=(maxOff-minOff);i++){
            sort(temp[i].begin(),temp[i].end());
            if(temp[i].size()>0)
                ans[i].insert(ans[i].end(),temp[i].begin(),temp[i].end());
        }    
    }
    return ans;
    }

int main(){

    Node *node1 = new Node(1);
    node1->left = new Node(2);
    node1->right = new Node(-3);
    node1->left->left = new Node(4);
    node1->left->right = new Node(-5);



    return 0;
}