/*
bubble sort using linked list
*/

#include <iostream>
using namespace std;

class node
{
    public:
    int data;
    node *next;
    node(int d)
    {
        data = d;
        next = NULL;
    }
};

void insert(node *&head, int d)
{
    if(head == NULL)
    {
        head = new node(d);
        return;
    }
    node *temp = head;
    while(temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = new node(d);
};

void display(node *head)
{
    while(head != NULL)
    {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

void bubbleSort(node *&head)
{
    int n = 0;
    node *temp = head;
    while(temp != NULL)
    {
        n++;
        temp = temp->next;
    }
    for(int i = 0; i < n-1; i++)
    {
        node *current = head;
        node *prev = NULL;
        node *nxt = head->next;
        for(int j = 0; j < n-i-1; j++)
        {
            if(current->data > nxt->data)
            {
                if(prev == NULL)
                {
                    current->next = nxt->next;
                    nxt->next = current;
                    head = nxt;
                    prev = nxt;
                    nxt = current->next;
                }
                else
                {
                    current->next = nxt->next;
                    nxt->next = current;
                    prev->next = nxt;
                    prev = nxt;
                    nxt = current->next;
                }
            }
            else
            {
                prev = current;
                current = nxt;
                nxt = nxt->next;
            }
        }
    }
};

int main()
{
    node *head = NULL;
    int tempNumberOfTimes;
    cout << "Enter the number of times you want to enter the elements of the linked list: ";
    cin >> tempNumberOfTimes;
    for(int i = 0; i < tempNumberOfTimes; i++)
    {
        int tempData;
        cout << "Enter the data: ";
        cin >> tempData;
        insert(head, tempData);
    }

    cout<<"Data before sorting: ";
    display(head);
    bubbleSort(head);
    cout<<"Data after sorting: ";
    display(head);
    return 0;
}