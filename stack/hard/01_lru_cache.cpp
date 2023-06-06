// Problem Link : https://leetcode.com/problems/lru-cache/

#include<bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;    
    Node() {
        left = right = nullptr;
    }

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};

class DLL{

public:
    Node* head;
    Node* tail;
    DLL() {
        head = tail = NULL;
    }

    void insertAtHead(Node* &newNode) {
        if (head == NULL) {
            head = tail = newNode;
        } 
        else {
            newNode->right = head;
            head->left = newNode;
            head = newNode;
        }
    }

    void insertNode(Node *&newNode) {
        if(!head){
            insertAtHead(newNode);
            return;
        }
        newNode->left = tail;
        tail->right = newNode;
        tail = newNode;
    }

    void deleteNode(Node*&node){
        Node*left = node->left;
        Node*right = node->right;
        if(!left and !right){
            head = tail = NULL;
        }
        else if(!left){
            head = head->right;
            delete(head->left);
            head->left = NULL;
        }
        else if(!right){
            tail = tail->left;
            delete(tail->right);
            tail->right = NULL;
        }
        else{
            Node*save = node;
            save->left->right = save->right;
            save->right->left = save->left;
            delete(node);  
        }        
        return;
    }
};

class LRUCache {
private:
    DLL *dl = new DLL();
    int size;
    map<int,pair<Node*,int>>keyStore;

public:
    LRUCache(int capacity) {
        size = capacity;
    }
    
    int get(int key) {
        if(keyStore.find(key)!=keyStore.end()){
            Node*save = keyStore[key].first;
            dl->deleteNode(save);
            Node*nd = new Node(key);
            keyStore[key].first = nd;
            dl->insertNode(nd);
            return keyStore[key].second;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(keyStore.find(key)!=keyStore.end()){
            Node*save = keyStore[key].first;
            dl->deleteNode(save);
            Node*nd = new Node(key);
            dl->insertNode(nd);
            keyStore[key].first = nd;
            keyStore[key].second = value;
        }
        else if(size<=0){
            keyStore.erase(dl->head->data);
            dl->deleteNode(dl->head);
            Node*node = new Node(key);
            keyStore[key].first = node;
            keyStore[key].second = value;
            dl->insertNode(node);
        }
        else{
            Node*node = new Node(key);
            keyStore[key].first = node;
            keyStore[key].second = value;
            dl->insertNode(node);
            size--;
        }
    }
};

// optimize and short code 

class LRUCache {
public:
    list<pair<int,int>>cache;
    map<int,list<pair<int,int>>::iterator> address;    
    int cap;
    LRUCache(int capacity) {
        cap = capacity;
    }
    
    void refreshCache(int key){
        int value = (*address[key]).second;
        cache.erase(address[key]);
        cache.push_front(make_pair(key,value));
        address[key] = cache.begin(); 
        return;
    }

    int get(int key) {
        if(address.find(key)!=address.end()){
            refreshCache(key);
            return (*address[key]).second;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(address.find(key)!=address.end()){
            refreshCache(key);
            (*address[key]).second = value;
        }
        else{
            cache.push_front(make_pair(key,value));
            address[key] = cache.begin();
            if(!cap){
                address.erase(cache.back().first);
                cache.pop_back();
            }
            else
                cap--;
        }
    }
};

int main(){
    return 0;
}