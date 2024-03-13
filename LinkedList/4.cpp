/*
    circular singly linked list
*/

#include <iostream>
using namespace std;

class node{
    public:
    int data;
    node *next;
    node(int d){
        data = d;
        next = NULL;
    }
};

void insertAtHead(node *&head, int d){
    node *n = new node(d);
    node *temp = head;
    n->next = head;
    if(temp!=NULL){
        while(temp->next!=head){
            temp = temp->next;
        }
        temp->next = n;
    }
    else{
        n->next = n;
    }
    head = n;
};

void insertAtTail(node *&head, int d){
    if(head==NULL){
        insertAtHead(head, d);
    }
    else{
        node *n = new node(d);
        node *temp = head;
        while(temp->next!=head){
            temp = temp->next;
        }
        temp->next = n;
        n->next = head;
    }
};
void insertAtPosition(node *&head, int d, int p){
    if(p==0){
        insertAtHead(head, d);
    }
    else{
        node *n = new node(d);
        node *temp = head;
        for(int i=0; i<p-1; i++){
            temp = temp->next;
        }
        n->next = temp->next;
        temp->next = n;
    }
};

void insertNodeByData(node *&head, int d, int data){
    node *n = new node(d);
    node *temp = head;
    while(temp->data!=data){
        temp = temp->next;
    }
    n->next = temp->next;
    temp->next = n;
};

void display(node *head){
    node *temp = head;
    while(temp->next!=head){
        cout<<temp->data<<"-> ";
        temp = temp->next;
    }
    cout<<temp->data<<endl;
};

void deleteAtHead(node *&head){
    node *temp = head;
    while(temp->next!=head){
        temp = temp->next;
    }
    node *todelete = head;
    temp->next = head->next;
    head = head->next;
    delete todelete;
};

void deleteAtTail(node *&head){
    node *temp = head;
    while(temp->next->next!=head){
        temp = temp->next;
    }
    node *todelete = temp->next;
    temp->next = head;
    delete todelete;
};

void deleteAtPosition(node *&head, int p){
    if(p==0){
        deleteAtHead(head);
    }
    else{
        node *temp = head;
        for(int i=0; i<p-1; i++){
            temp = temp->next;
        }
        node *todelete = temp->next;
        temp->next = temp->next->next;
        delete todelete;
    }
}; 

int main(){

    node *head = NULL;
    insertAtHead(head, 1);
    insertAtHead(head, 2);
    insertAtHead(head, 3);
    display(head);
    insertAtTail(head, 4);
    insertAtTail(head, 5);
    insertAtTail(head, 6);
    display(head);
    insertAtPosition(head, 7, 2);
    insertAtPosition(head, 8, 3);
    display(head);
    insertNodeByData(head, 9, 4);
    insertNodeByData(head, 10, 5);
    display(head);
    deleteAtHead(head);
    display(head);
    deleteAtTail(head);
    display(head);
    deleteAtPosition(head, 2);
    deleteAtPosition(head, 3);
    display(head);
    
    return 0;
};