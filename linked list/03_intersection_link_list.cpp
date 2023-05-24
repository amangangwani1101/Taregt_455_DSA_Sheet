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
    void f(){
        cout<<"Working"<<endl;
    }
};


// Approach 1 : try to find length of both list and then if not equall thrn shift ptr of largest link till length of both link becomes equal 


// Optimize And beter Approach : iterate over a link and link last node of it to its head now question boils down to find cycle in linked list and node where cycle begin that is intersection of 2 linkk list

node*cycleinlist(node*head){
        node*slowPtr = head;
        node*fastPtr = head;
        while(fastPtr and fastPtr->next){
            slowPtr = slowPtr->next;
            fastPtr = fastPtr->next->next;
            if(slowPtr==fastPtr)
                break;
        }

        // no cycle
        if(!fastPtr or !fastPtr->next)
            return NULL;
        slowPtr = head;
    
        // cycle present
        while(slowPtr!=fastPtr){
            slowPtr = slowPtr->next;
            fastPtr = fastPtr->next;
        }
        return slowPtr;
    }
    node *getIntersectionNode(node *headA, node *headB) {
        node*save = headB;
        if(!headB) return NULL;
        while(save->next){
            save = save->next;
        }        
        save->next = headB;
        node*val = cycleinlist(headA);
        save->next = NULL;
        return val;
    }

void print(node*head)
{
    node* temp = head;

    while (temp != NULL) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

int main(){
    node*nd[2];
    nd[0] = new node(9);
    nd[0]->next = new node(9);
    nd[0]->next->next = new node(9);
    nd[0]->next->next->next = new node(9);

    nd[1] = new node(9);
    nd[1]->next = new node(9);

    print(getIntersectionNode(nd[0],nd[1]));
    return 0;
}
