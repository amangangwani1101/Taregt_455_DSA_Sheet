//Problem Link : https://leetcode.com/problems/maximum-width-of-binary-tree/submissions/

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
// note : for a given root , left 2*node+1 ,right 2*node+2

// Approach : for every level store first not null value[fVal] and last not null value[sVal] and diffrence of them is Ans : sVal-fVal+1
int maxWidthTree(Node*root){
    queue<pair<Node*,long long int >>q;
    int ans=0;
    q.push({root,0});
    while(!q.empty()){
        int sz = q.size();
        long long int fVal=-1,sVal=0;
        int del = q.front().second;
        while(sz--){
            Node* el = q.front().first;
            long long int  nodePos = q.front().second - del;
            q.pop();
            if(fVal==-1) fVal = nodePos;
            sVal = nodePos;
            if(el->left)
                q.push({el->left,2ll*nodePos+1});
            if(el->right)
                q.push({el->right,2ll*nodePos+2});
        }
        ans = max(ans,(int)(sVal-fVal+1));
    }
    return ans;
}

int main(){

    Node *node1 = new Node(1);
    node1->left = new Node(2);
    node1->right = new Node(-3);
    node1->left->left = new Node(4);
    node1->left->right = new Node(-5);

    cout<<maxWidthTree(node1);
    return 0;
}