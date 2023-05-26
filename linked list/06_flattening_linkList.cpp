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

    // print(rotateListByK(nd,2));
    return 0;
}
