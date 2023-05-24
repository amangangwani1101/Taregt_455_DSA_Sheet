//Problem Link : https://practice.geeksforgeeks.org/problems/burning-tree/1

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

// approach : first try to find node then do a bfs traversal till ll nodes are marked visited :: but problem lies on fact how to go upward from node :: for that just do a bfs traversal initally and save parent of nodes in a hashmap so that during bfs we can acces upward parent using it

int burningTree(Node*root,int val){
    queue<Node*>mark;
    unordered_map<Node*,Node*>save;
    mark.push(root);
    save[root] = NULL;
    Node*start = NULL;
    while(!mark.empty()){
        Node*top = mark.front();
        mark.pop();
        if(top->val==val) start = top;
        if(top->left){
            mark.push(top->left);
            save[top->left] = top;
        }
        if(top->right){
            mark.push(top->right);
            save[top->right] = top;
        }
    }
    
    // now solution begins.. :)
    unordered_map<Node*,bool>vis;
    mark.push(start);
    int time=0;
    while(!mark.empty()){
        int sz = mark.size();
        while(sz--){
            Node*top = mark.front();
            mark.pop();
            vis[top] = true;

            if(save[top] and !vis[save[top]])
                mark.push(save[top]); 

            if(top->left and !vis[top->left])
                mark.push(top->left);

            if(top->right and !vis[top->right])
                mark.push(top->right);
        }
        if(mark.empty()) break;
        time++;
    }
    return time;
}

int main(){

    Node *node1 = new Node(1);
    node1->left = new Node(2);
    node1->right = new Node(-3);
    node1->left->left = new Node(4);
    node1->left->right = new Node(-5);

    cout<<burningTree(node1,-3);
    return 0;
}