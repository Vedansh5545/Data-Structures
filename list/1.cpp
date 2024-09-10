/* implementing Linked List ADT using array*/

#include <iostream>

using namespace std;

class List {
    private:
        int *arr;
        int capacity;
        int size;
    public:
        List(int capacity);
        void insert(int index, int element);
        void remove(int index);
        int get(int index);
        void set(int index, int element);
        int getSize();
        int removeAt(int index);
        bool isEmpty();
        bool isFull();
        void display();
        void replace(int oldElement, int newElement);
        void clear();
        ~List();
};

List::List(int capacity){
    this->capacity = capacity;
    this->size = 0;
    this->arr = new int[capacity];
}

void List::insert(int index, int element){
    if(index < 0 || index > size){
        cout << "Invalid index" << endl;
        return;
    }
    if(size == capacity){
        cout << "List is full" << endl;
        return;
    }
    for(int i = size; i > index; i--){
        arr[i] = arr[i-1];
    }
    arr[index] = element;
    size++;
}

void List::remove(int index){
    if(index < 0 || index >= size){
        cout << "Invalid index" << endl;
        return;
    }
    for(int i = index; i < size-1; i++){
        arr[i] = arr[i+1];
    }
    size--;
}

int List::get(int index){
    if(index < 0 || index >= size){
        cout << "Invalid index" << endl;
        return -1;
    }
    return arr[index];
}

void List::set(int index, int element){
    if(index < 0 || index >= size){
        cout << "Invalid index" << endl;
        return;
    }
    arr[index] = element;
}

int List::getSize(){
    return size;
}

int List::removeAt(int index){
    if(index < 0 || index >= size){
        cout << "Invalid index" << endl;
        return -1;
    }
    int element = arr[index];
    for(int i = index; i < size-1; i++){
        arr[i] = arr[i+1];
    }
    size--;
    return element;
}

bool List::isEmpty(){
    return size == 0;
}

bool List::isFull(){
    return size == capacity;
}

void List::display(){
    for(int i = 0; i < size; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}

void List::replace(int oldElement, int newElement){
    for(int i = 0; i < size; i++){
        if(arr[i] == oldElement){
            arr[i] = newElement;
        }
    }
}

void List::clear(){
    size = 0;
}

List::~List(){
    delete[] arr;
}



int main(){
    List l(5);
    l.insert(0, 10);
    l.insert(1, 20);
    l.insert(2, 30);
    l.insert(3, 40);
    l.insert(4, 50);
    l.display();
    l.remove(2);
    l.display();
    l.set(1, 100);
    l.display();
    cout << l.get(2) << endl;
    cout << l.getSize() << endl;
    cout << l.removeAt(1) << endl;
    l.display();
    cout << l.isEmpty() << endl;
    cout << l.isFull() << endl;
    l.replace(40, 400);
    l.display();
    l.clear();
    l.display();
    
    return 0;

};

