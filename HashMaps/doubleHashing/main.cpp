#include "function.h"

int main(){

    DoubleHashing dh(10);

    while(true){
        cout << "1. Insert" << endl;
        cout << "2. Delete" << endl;
        cout << "3. Search" << endl;
        cout << "4. Display" << endl;
        cout << "5. Exit" << endl;
        int choice;
        cout << "Enter your choice: ";
        cin >> choice;
        if(choice == 1){
            int key;
            cout << "Enter key to insert: ";
            cin >> key;
            dh.insertItem(key);
        }
        else if(choice == 2){
            int key;
            cout << "Enter key to delete: ";
            cin >> key;
            dh.deleteItem(key);
        }
        else if(choice == 3){
            int key;
            cout << "Enter key to search: ";
            cin >> key;
            dh.search(key);
        }
        else if(choice == 4){
            dh.displayHash();
        }
        else if(choice == 5){
            break;
        }
        else{
            cout << "Invalid choice" << endl;
        }
    }


    return 0;
};