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

node* front = NULL;
node* rear = NULL;

bool isEmpty(){
    if(front==NULL || rear==NULL){
        return true;
    }
    return false;
};

void enqueue(int d){
    node* n = new node(d);
    if(front==NULL){
        front=n;
        rear=n;
        return;
    }
    rear->next=n;
    rear=n;
};

void dequeue(){
    if(isEmpty()){
        cout<<"Queue is empty"<<endl;
        return;
    }
    node* temp = front;
    front=front->next;
    delete temp;
};
void showFront(){
    if(isEmpty()){
        cout<<"Queue is empty"<<endl;
        return;
    }
    cout<<front->data<<endl;
};

void displayQueue(){
    if(isEmpty()){
        cout<<"Queue is empty"<<endl;
        return;
    }
    node* temp = front;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
};

int main(){
    enqueue(1);
    enqueue(2);
    enqueue(3);
    displayQueue();
    dequeue();
    displayQueue();
    cout<<isEmpty()<<endl;
    showFront();

    return 0;
};