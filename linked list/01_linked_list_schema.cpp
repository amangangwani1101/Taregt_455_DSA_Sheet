// Alternate method to declare the class
// in order to minimize the
// memory allocation work
  
#include <bits/stdc++.h>
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

class LinkList{
    
    // Function to insert an element
    // at head position
    node*head=NULL;
    public:
    LinkList(){
        head = new node(-1);
    }

    node* retunrHead(){
        return head;
    }

    void insertathead(int val)
    {
        node* n = new node(val);
        if(head->data==-1){
            head = n;
            return;
        }
        n->next = head;
        head = n;
    }
    
    // Function to insert a element
    // at a specified position
    void insertafter(int key, int val)
    {
        node* n = new node(val);
        if (key == head->data) {
            n->next = head->next;
            head->next = n;
            return;
        }
    
        node* temp = head;
        while (temp->data != key) {
            temp = temp->next;
            if (temp == NULL) {
                return;
            }
        }
        n->next = temp->next;
        temp->next = n;
    }
    
    // Function to insert an
    // element at the end
    void insertattail(int val)
    {
        node* n = new node(val);
        if (head == NULL) {
            head = n;
            return;
        }
    
        node* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = n;
    }
    
    // function to delete at head
    void deleteathead(int val){
        node*temp = head;
        head = head->next;
        delete(temp);
        return;
    }

    void deletenode(int val){
        node*prev = NULL;
        node*curr = head;
        
        // value is at head
        if(curr->data==val) {
            deleteathead(val);
            return;
        }
            
        while(curr and curr->data!=val){
            prev = curr;
            curr = curr->next;
        } 
        
        // node not present
        if(!curr) return;
        
        // present
        prev->next = curr->next;
        delete(curr);
        return;
    }

    // reverse a linkList
    node* reverselink(node*startPtr){
        
        node*prev = NULL;
        node*curr = startPtr;

        // empty linklist
        if(!curr) return NULL;
        node*next = startPtr->next;
        while(next){
            curr->next = prev;
            prev = curr;
            curr = next;
            next = next->next;
        }
        curr->next = prev;
        return curr;
    }

    
    // middle of a linked list -- TortoiseHare Method(Slow/Fast Pointer)
    node* middleoflist(){
        node*slowPtr = head;
        node*fastPtr = head;
        while(fastPtr and fastPtr->next){
            slowPtr = slowPtr->next;
            fastPtr=  fastPtr->next->next;
        }
        return slowPtr;
    }

    // cycle in link list
    // if return NULL : no cycle
    // else cycle is present at node returned
    node*cycleinlist(){
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
        
        // cycle present
        slowPtr = head;
        while(slowPtr!=fastPtr){
            slowPtr = slowPtr->next;
            fastPtr = fastPtr->next;
        }
        return slowPtr;
    }

    // function to find length of link list
    int getLengthList(node*head){
        int length=0;
        while(head){
            head = head->next;
            length++;
        }
        return length;
    }

    // Function to print the
    // singly linked list
    void print(node*head)
    {
        node* temp = head;
    
        while (temp != NULL) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }

    node*merge2list(node*head1,node*head2){
        node*newHead = NULL;
        node*temp = NULL;
        while(head1 and head2){
            if(head1->data<=head2->data){
                if(!temp) temp = head1,newHead = head1;
                else temp->next = head1,temp = temp->next;
                head1 = head1->next;
            }
            else{
                if(!temp) temp = head2,newHead = head2;
                else temp->next = head2,temp = temp->next;
                head2 = head2->next;
            }
        }   
        if(head1) temp->next = head1;
        if(head2) temp->next = head2;
        return newHead;
    }
};
  
// Main function
int main()
{
  
    // Declaring an empty linked list
    LinkList* link = new LinkList();
    return 0;
}