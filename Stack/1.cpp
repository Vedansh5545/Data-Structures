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

node* top = NULL;

bool isEmpty(){
    if(top==NULL){
        return true;
    }
    return false;
};

void push(int d){
    node *temp = new node(d);
    temp->next = top;
    top = temp;
};

void pop(){
    if(isEmpty()){
        cout<<"Stack is empty"<<endl;
        return;
    }
    node *temp = top;
    top = top->next;
    delete temp;
};

void showTop(){
    if(isEmpty()){
        cout<<"Stack is empty"<<endl;
        return;
    }
    cout<<"Top element is: "<<top->data<<endl;
};

void displayStack(){
    if(isEmpty()){
        cout<<"Stack is empty"<<endl;
        
    }
    node *temp = top;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
};

int main(){
    push(10);
    push(20);
    push(30);
    push(40);
    push(50);
    push(60);
    push(70);
    push(80);
    push(90);
    push(100);
    push(110);
    push(120);
    push(130);
    push(140);
    push(150);
    push(160);
    push(170);
    push(180);
    push(190);
    push(200);
    push(210);
    push(220);
    push(230);
    push(240);
    push(250);
    push(260);
    push(270);
    push(280);
    push(290);
    displayStack();
    pop();
    displayStack();
    pop();
    displayStack();
    cout<<isEmpty()<<endl;
    pop();
    cout<<isEmpty()<<endl;
    pop();
    cout<<isEmpty()<<endl;
    displayStack();
    return 0;
}