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

// sort 0,1,2 link list : approach is to from 3 list of 0,1,2 then attach them
node* sort012list(node*head){
    node*zero = new node(-1);
    node*one = new node(-1);
    node*two = new node(-1);
    node*zeroS = zero,*oneS=one,*twoS=two;
    while(head){
        if(head->data==0){
            zero->next = head;
            zero = zero->next;
        }
        else if(head->data==1){
            one->next = head;
            one = one->next;
        }
        else{
            two->next = head;
            two = two->next;
        }
        head = head->next;
    }

    zero->next = (oneS->next)?oneS->next:twoS->next;
    one->next = twoS->next;
    two->next = NULL;
    
    head = zeroS->next;
    
    delete(zeroS);
    delete(oneS);
    delete(twoS);
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
    node*nd;
    nd = new node(2);
    nd->next = new node(0);
    nd->next->next = new node(1);
    nd->next->next->next = new node(0);

    print(sort012list(nd));
    return 0;
}
