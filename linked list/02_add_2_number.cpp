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


node*add2linkList(node*link1,node*link2){
    int carry=0;
    node*head=link1,*prev;
    while(link1 and link2){
        int sum = link1->data + link2->data + carry;
        prev = link1;
        link1->data = sum%10;
        carry = (sum/10);
        link1 = link1->next;
        link2 = link2->next;
    }
    if(link1){
        while(link1){
            int sum = link1->data  + carry;
            link1->data = sum%10;
            carry = (sum/10);
            prev = link1;
            link1 = link1->next;        
        }
    }
    if(link2){
        prev->next = link2;
        while(link2){
            int sum = link2->data  + carry;
            link2->data = sum%10;
            carry = (sum/10);
            prev = link2;
            link2 = link2->next;        
        }
    }
    if(carry)
        prev->next = new node(carry);
    
    return head;
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

    print(add2linkList(nd[0],nd[1]));
    return 0;
}
