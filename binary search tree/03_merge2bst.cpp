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

    // merge 2 bst;

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

    vector<int> merge2BST(Node*root1,Node*root2){
        Node*temp1=root1,*temp2=root2;
        while(temp1->left)
            temp1 = temp1->left;
        
        while(temp2->left)
            temp2 = temp2->left;

        vector<int>ans;
        while(temp1 and temp2){
            if(temp1->val<temp2->val){
                ans.push_back(temp1->val);
                temp1 = inorderPreceder(root1,temp1->val);
            }
            else{
                ans.push_back(temp2->val);
                temp2 = inorderPreceder(root2,temp2->val);
            }
        }
        while(temp2){
            ans.push_back(temp2->val);
            temp2 = inorderPreceder(root2,temp2->val);
        }

        while(temp1){
            ans.push_back(temp1->val);
            temp1 = inorderPreceder(root2,temp1->val);
        }

        return ans;
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