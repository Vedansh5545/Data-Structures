/*
insertion sort implementation using linked listss
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
void display(node *head){
    while(head != NULL){
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

void insertionSort(node *&head) {
    if (head == NULL || head->next == NULL)
        return;

    node *sorted = NULL;

    node *current = head;
    while (current != NULL) {
        node *next = current->next;

        if (sorted == NULL || sorted->data >= current->data) {
            current->next = sorted;
            sorted = current;
        } else {
            node *temp = sorted;
            while (temp != NULL) {
                if (temp->next == NULL || temp->next->data > current->data) {
                    current->next = temp->next;
                    temp->next = current;
                    break;
                }
                temp = temp->next;
            }
        }
        current = next;
    }
    head = sorted;
}


void inseart(node *&head, int d){
    if(head == NULL){
        head = new node(d);
        return;
    }
    node *temp = head;
    while(temp->next != NULL){
        temp = temp->next;
    }
    temp->next = new node(d);
}

int main(){

    node *head = NULL;
    int NumberOfElements;
    cout << "Enter the number of elements you want to enter: ";
    cin >> NumberOfElements;
    for(int i = 0; i < NumberOfElements; i++){
        int d;
        cout << "Enter the element " << i+1 << ": ";
        cin >> d;
        inseart(head, d);
    }
    cout << "The linked list before sorting is: ";
    display(head);
    insertionSort(head);
    cout << "The linked list after sorting is: ";
    display(head);
    return 0;

};