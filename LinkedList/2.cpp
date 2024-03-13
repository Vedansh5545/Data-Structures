/*
    singly linked list -"
    This code implements a linked list data structure in C++. 

    The `node` class represents a single node in the linked list. Each node contains an integer value (`data`) and a pointer to the next 
    node (`next`). The constructor of the `node` class initializes the data and sets the next pointer to `NULL`.

    The code also includes several functions to manipulate the linked list:
    - `insertHead` inserts a new node at the beginning of the list.
    - `insertTail` inserts a new node at the end of the list.
    - `InsertAtPosition` inserts a new node at a specified position in the list.
    - `Display` prints the values of all nodes in the list.
    - `deleteNodeByValue` deletes the first occurrence of a node with a given value.
    - `deleteNodeByPosition` deletes a node at a specified position in the list.

    In the `main` function, a linked list is created and various operations are performed on it, such as inserting nodes at the head and 
    tail, inserting nodes at specific positions, deleting nodes by value and position, and displaying the final list.
    
    "


*/

#include <iostream>

using namespace std;

class node{
    public:
        int data;
        node *next;
        node(int d){
            data=d;
            next=NULL;
        }
};

void insertHead(node * &head, int val){
    node *n = new node(val);
    n->next = head;
    head = n;
};

void insertTail(node * &head, int val){
    node *n = new node(val);
    if(head == NULL){
        head = n;
        return;
    }
    node *temp = head;
    while(temp->next !=NULL){
        temp = temp->next;
    }
    temp->next = n;
};

void InsertAtPosition(node * &head, int val, int pos){
    node *n = new node(val);
    if(pos == 1){
        n->next = head;
        head = n;
        return;
    }
    node *temp = head;
    for(int i=1; i<pos-1; i++){ // Traverse to the position before the desired position
        temp = temp->next;
    }
    n->next = temp->next;
    temp->next = n;
};

void Display(node *head){
    node *temp = head;
    while(temp != NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
};

void deleteNodeByValue(node* head, int val){
    node* temp = head;
    while(temp->next->data != val){
        temp = temp->next;
    }
    node* todelete = temp->next;
    temp->next = temp->next->next;
    delete todelete;
};

void deleteNodeByPosition(node* head, int pos){
    node* temp = head;
    for(int i=1; i<pos-1; i++){ // Traverse to the position before the desired position
        temp = temp->next;
    }
    node* todelete = temp->next;
    temp->next = temp->next->next;
    delete todelete;
};

int main(){

    node* head = NULL;
    insertHead(head, 1);
    Display(head);
    insertHead(head, 2);
    insertHead(head, 3);
    insertHead(head, 4);
    Display(head);
    
    insertTail(head, 5);
    insertTail(head, 6);
    insertTail(head, 7);
    insertTail(head, 8);
    Display(head);
    InsertAtPosition(head, 9, 3);
    InsertAtPosition(head, 10, 4);
    InsertAtPosition(head, 11, 5);
    Display(head);
    deleteNodeByValue(head,10);
    Display(head);
    deleteNodeByPosition(head,2);
    Display(head);



    return 0;
};