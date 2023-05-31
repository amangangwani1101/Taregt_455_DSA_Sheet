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


// optimized code : using bst iterator we will always maintain 2 stack one which will travel bst in increasing order and other will travrse in decreasing order ans using 2 pointer concept will check for our required sum 
// TC : O(N) SC : O(H)
class BSTIterator{
    private:
        stack<Node*>s;
        bool reverse;
        void pushAll(Node*root){
            while(root)
            {
                s.push(root);
                if(reverse)
                    root = root->right;
                else
                    root = root->left;
            }
        }
    public:
        BSTIterator(Node*root,bool isReverse)
        {
            reverse = isReverse;
            pushAll(root);
        }

        bool hasNext(){
            return s.empty();
        }

        int next(){
            Node*top = s.top();
            s.pop();
            if(reverse) pushAll(top->left);
            else pushAll(top->right);
            return top->val;
        }
};

class BST{
public:

    // find a pair with given target in bst
    // TC : O(NlogN) SC : O(N)
    bool searchBST(Node*root,int val){
        while(root){
            if(root->val==val)
                return true;
            if(root->val>val)
                root = root->left;
            else    
                root = root->right;
        }
        return false;
    }

    bool checkPairTgtBST(Node*root,int target,Node*aRoot){
        if(!root) return false;
        
        bool left = checkPairTgtBST(root->left,target,aRoot);
        int val1 = root->val;
        int val2 = target - root->val;
        if(val1!=val2 and searchBST(aRoot,val2))
            return true;
        bool right = checkPairTgtBST(root->right,target,aRoot);
        return false;
    }

     bool searchTargetBST(Node*root,int tgt){
        BSTIterator l(root,false);
        BSTIterator r(root,true);

        int i = l.next();
        int j = r.next();

        while(!i and !j){
            if(i+j==tgt)
                return true;
            else if(i+j<tgt)
                i = l.next();
            else    
                j = r.next();
        }
        return false;
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