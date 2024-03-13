/*
    doubly linked list
*/

#include <iostream>

using namespace std;

class node{
    public:
        int data;
        node *next;
        node *prev;
        node(int d){
            data=d;
            next=NULL;
            prev=NULL;
        }
};

void display(node *head){
    node *temp = head;
    while(temp != NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
};
int getLength(node *head){
    node *temp = head;
    int count = 0;
    while(temp != NULL){
        count++;
        temp = temp->next;
    }
    return count;
};

void insertHead(node * &head, int val){
    node *temp = new node(val);
    temp->next = head;
    if(head != NULL){
        head->prev = temp;
    }
    head = temp;
};

void insertTail(node * &head, int val){
    node *temp = new node(val);
    if(head == NULL){
        head = temp;
        return;
    }
    node *last = head;
    while(last->next != NULL){
        last = last->next;
    }
    last->next = temp;
    temp->prev = last;
};

void insertAtPosition(node * &head, int val, int pos){
    if(pos < 1 || pos > getLength(head)){
        cout<<"Invalid position"<<endl;
        return;
    }
    if(pos == 1){
        insertHead(head, val);
        return;
    }
    if(pos == getLength(head)){
        insertTail(head, val);
        return;
    }
    node *temp = new node(val);
    node *prev = head;
    for(int i=1; i<pos-1; i++){
        prev = prev->next;
    }
    node *next = prev->next;
    prev->next = temp;
    temp->prev = prev;
    temp->next = next;
    next->prev = temp;
};

void deleteHead(node * &head){
    node *todelete = head;
    head = head->next;
    head->prev = NULL;
    delete todelete;
};

void deleteTail(node * &head){
    node *prev = head;
    while(prev->next!= NULL){
        prev = prev->next;
    }
    node *todelete = prev->next;
    prev->next = NULL;
    delete todelete;
};

void deleteNode(node * &head, int pos){
    if(pos < 1 || pos > getLength(head)){
        cout<<"Invalid position"<<endl;
        return;
    }
    if(pos == 1){
        deleteHead(head);
        return;
    }
    if(pos == getLength(head)){
        deleteTail(head);
        return;
    }
    node *prev = head;
    for(int i=1; i<pos-1; i++){
        prev = prev->next;
    }
    node *todelete = prev->next;
    node *next = todelete->next;
    prev->next = next;
    next->prev = prev;
    delete todelete;
};

int main(){

    node *head = NULL;
    insertHead(head, 1);
    insertHead(head, 2);
    insertHead(head, 3);
    display(head);
    insertTail(head, 4);
    insertTail(head, 5);
    insertTail(head, 6);
    display(head);
    insertAtPosition(head, 7, 2);
    insertAtPosition(head, 8, 3);
    insertAtPosition(head, 9, 4);
    display(head);
    deleteNode(head, 1);
    display(head);
    deleteTail(head);
    deleteHead(head);
    display(head);
    return 0;
}

