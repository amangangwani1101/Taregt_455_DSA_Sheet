#include<bits/stdc++.h>
using namespace std;

class node {
public:
    int data;
    node* next;
    
    // A constructor is called here
    node(int value)
    {
  
        // It automatically assigns the
        // value to the data
        data = value;
  
        // Next pointer is pointed to NULL
        next = NULL;
    }
};

    int getLengthList(node*head){
        int length=0;
        while(head){
            head = head->next;
            length++;
        }
        return length;
    }

    node*rotateListByK(node*head,int k){
        int length = getLengthList(head);
        if(!length) return NULL;
        
        k = k%length;
        if(!k) return head;
        node*start = head,*end = head,*prev=NULL,*endPrev = NULL;
        
        while(k--){
            end = end->next;
        }
        
        while(end){
            prev = start;
            endPrev = end;
            start = start->next;
            end = end->next;
        }
        
        prev->next = NULL;
        endPrev->next = head;
        return start;
    }

void print(node*head)
{
    node* temp = head;

    while (temp != NULL) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL";
}

int main(){
    node*nd;
    nd = new node(2);
    nd->next = new node(0);
    nd->next->next = new node(1);
    nd->next->next->next = new node(0);

    print(rotateListByK(nd,2));
    return 0;
}
