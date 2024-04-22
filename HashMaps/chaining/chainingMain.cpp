#include "chaining.h"

int main() {
   
    cout << "Enter the bucket size: ";
    int bucketSize;
    cin >> bucketSize;
    HashMap h(bucketSize);
    cout<<"1. Insert element into the table"<<endl;
    cout<<"2. Search element from the key"<<endl;
    cout<<"3. Delete element at a key"<<endl;
    cout<<"4. Display"<<endl;
    cout<<"5. Exit"<<endl;

    while(true){
        int choice;
        cout << "Enter your choice: ";
        cin >> choice;
        switch(choice){
            case 1:
                cout << "Enter the element to be inserted: ";
                int key;
                cin >> key;
                h.insertItem(key);
                break;
            case 2:
                cout << "Enter the element to be searched: ";
                cin >> key;
                if(h.searchItem(key) != -1){
                    cout << "Element found in the table at index " << h.searchItem(key) << endl;
                } else {
                    cout << "Element not found in the table" << endl;
                }
                break;
            case 3:
                cout << "Enter the element to be deleted: ";
                cin >> key;
                h.deleteItem(key);
                break;
            case 4:
                h.display();
                break;
            case 5:
                exit(0);
            default:
                cout << "Invalid choice" << endl;
        }
    }

   
    return 0;
}