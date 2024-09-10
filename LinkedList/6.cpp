/*Double linked list*/
#include <iostream>
using namespace std;

class Node {
    public:
        int data;
        Node *next;
        Node *prev;
};

class LinkedList {
    private:
        Node *head;
    public:
        LinkedList();
        void insert(int element);
        void remove(int element);
        void display();
        bool search(int element);
        void clear();
        ~LinkedList();
};

LinkedList::LinkedList(){
    head = NULL;
}

void LinkedList::insert(int element){
    Node *newNode = new Node();
    newNode->data = element;
    newNode->next = NULL;
    newNode->prev = NULL;
    if(head == NULL){
        head = newNode;
    } else {
        Node *temp = head;
        while(temp->next != NULL){
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->prev = temp;
    }
}

void LinkedList::remove(int element){
    if(head == NULL){
        cout << "List is empty" << endl;
        return;
    }
    if(head->data == element){
        Node *temp = head;
        head = head->next;
        head->prev = NULL;
        delete temp;
        return;
    }
    Node *temp = head;
    while(temp->next != NULL){
        if(temp->next->data == element){
            Node *toDelete = temp->next;
            temp->next = temp->next->next;
            if(temp->next != NULL){
                temp->next->prev = temp;
            }
            delete toDelete;
            return;
        }
        temp = temp->next;
    }
    cout << "Element not found in the list" << endl;
}

void LinkedList::display(){
    if(head == NULL){
        cout << "List is empty" << endl;
        return;
    }
    Node *temp = head;
    while(temp != NULL){
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

bool LinkedList::search(int element){
    Node *temp = head;
    while(temp != NULL){
        if(temp->data == element){
            return true;
        }
        temp = temp->next;
    }
    return false;
}

void LinkedList::clear(){
    Node *temp = head;
    while(temp != NULL){
        Node *toDelete = temp;
        temp = temp->next;
        delete toDelete;
    }
    head = NULL;
}

int main(){
    
        LinkedList l;
        cout<<"1. Insert element into the list"<<endl;
        cout<<"2. Search element from the list"<<endl;
        cout<<"3. Delete element from the list"<<endl;
        cout<<"4. Display"<<endl;
        cout<<"5. Exit"<<endl;
    
        while(true){
            int choice;
            cout << "Enter your choice: ";
            cin >> choice;
            switch(choice){
                case 1:
                    int element;
                    cout << "Enter element: ";
                    cin >> element;
                    l.insert(element);
                    break;
                case 2:
                    cout << "Enter element to search: ";
                    cin >> element;
                    if(l.search(element)){
                        cout << "Element found in the list" << endl;
                    } else {
                        cout << "Element not found in the list" << endl;
                    }
                    break;
                case 3:
                    cout << "Enter element to delete: ";
                    cin >> element;
                    l.remove(element);
                    break;
                case 4:
                    l.display();
                    break;
                case 5:
                    exit(0);
                default:
                    cout << "Invalid choice" << endl;
            }
        }
    
        return 0;
        
}