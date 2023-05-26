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

string serialize(Node*root){
    string serializer = "";
    if(!root) return serializer;
    queue<Node*>q;
    q.push(root);
    while(!q.empty()){
        Node*top= q.front();
        q.pop();
        if(top) serializer+=(to_string(root->val)+"|");
        else serializer+=("#|");
        if(top){
            q.push(top->left);
            q.push(top->right);
        }
    }
    return serializer;
}

Node* deserialize(string serialized){
    if(!serialized.size()) return NULL;
    stringstream s(serialized);
    string store;
    getline(s,store,'|');
    Node*root = new Node(stoi(store));
    queue<Node*>q;
    q.push(root);
    while(!q.empty()){
        Node*temp = q.front();
        q.pop();
        
        getline(s,store,'|');
        if(store=="#")
            temp->left = NULL;
        else{
            Node*nd = new Node(stoi(store));
            temp->left = nd;
            q.push(nd);
        }

        getline(s,store,'|');
        if(store=="#")
            temp->right = NULL;
        else{
            Node*nd = new Node(stoi(store));
            temp->right = nd;
            q.push(nd);
        }
    }
    return root;
}

int main(){

    Node *node1 = new Node(1);
    node1->left = new Node(2);
    node1->right = new Node(-3);
    node1->left->left = new Node(4);
    node1->left->right = new Node(-5);

    string serial = serialize(node1);
    Node*deserial = deserialize(serial);
    return 0;
}