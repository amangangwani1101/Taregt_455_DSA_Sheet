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

class Tree{
public:

    // maximum height of a tree
    int getHeight(Node*root){
        if(!root) return 0;
        int left = getHeight(root->left);
        int right = getHeight(root->right);

        return 1 + max(left,right);
    }

    // preorder traversal iterative
    void preOrderTraversal(Node*root,vector<int>&ans){
        stack<Node*>st;
        st.push(root);
        while(!st.empty()){
            Node*curr = st.top();
            st.pop();
            ans.push_back(curr->val);
            if(curr->right){
                st.push(curr->right);
            }
            if(curr->left){
                st.push(curr->left);
            }
        }
    }

    // inorder travseral iterative
    void inorderTraversal(Node*root,vector<int>&ans){
        stack<Node*>st;
        while(true){
            if(root){
                st.push(root);
                root = root->left;
            }
            else{
                if(st.empty()) break;
                root = st.top();
                st.pop();
                ans.push_back(root->val);
                root = root->right;
            }
        }
        return;
    }
    
    // postorder traversal iterative
    void postOrderTraversal(Node*root,vector<int>&ans){
        
        stack<Node*>st;
        while(root or !st.empty()){
            if(root){
                st.push(root);
                root = root->left;
            }
            else{
                Node* temp = st.top();
                if(!temp->right)
                {
                    ans.push_back(temp->val);
                    st.pop();
                    while(!st.empty() and st.top()->right==temp){
                        temp = st.top();
                        st.pop();
                        ans.push_back(temp->val);
                    }
                }
                else
                    root = temp->right;
            }
        }
    }

    // level order traserval
    void levelordertraversal(Node*root,vector<int>&ans){
        queue<Node*>qu;
        qu.push(root);
        while(!qu.empty()){
            int sz = qu.size();
            for(int itr=0;itr<sz;itr++){
                Node*top = qu.front();
                qu.pop();
                ans.push_back(top->val);

                if(top->left)
                    qu.push(top->left);
                if(top->right)
                    qu.push(top->right);
            }
        }
    }

    // print tree
    void printVectorTree(vector<int>&ans){  
        for(int val:ans)
            cout<<val<<" ";
        return;
    }

};
int main(){
    Tree * obj = new Tree();
    vector<int>ans;

    Node *node = new Node(1);
    node->left = new Node(2);
    node->right = new Node(3);
    node->left->left = new Node(4);
    node->left->right = new Node(5);

    return 0;
}