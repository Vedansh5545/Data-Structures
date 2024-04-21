#include <iostream>
#include <vector>
#include <string>

/*
this code is a simple implementation of a hash table using chaining with linked lists
it has the following functions:
1. insert(key, value) - insert a key-value pair into the hash table
2. search(key) - search for a value by key
3. deleteKey(key) - delete a key-value pair from the hash table
4. display() - display the hash table

Time Complexity:
- Insertion: O(1) on average
- Search: O(1) on average
- Deletion: O(1) on average

Space Complexity: O(n)

*/

// Node structure for the linked list
struct Node {
    std::string key;
    int value;
    Node* next;

    Node(std::string key, int value) : key(key), value(value), next(nullptr) {}
};

// Hash table class using chaining with linked lists
class HashTable {
private:
    std::vector<Node*> table;
    int capacity;

    // Hash function to calculate index
    int hashFunction(std::string key) {
        int hash = 0;
        for (char c : key) {
            hash = (hash * 31 + c) % capacity;  // Using a prime number 31
        }
        return hash;
    }

public:
    HashTable(int size) : capacity(size) {
        table.resize(capacity, nullptr);
    }

    ~HashTable() {
        for (Node* head : table) {
            while (head != nullptr) {
                Node* temp = head;
                head = head->next;
                delete temp;
            }
        }
    }

    // Insert key-value pair into the hash table
    void insert(std::string key, int value) {
        int index = hashFunction(key);
        Node* newNode = new Node(key, value);
        if (table[index] == nullptr) {
            table[index] = newNode;
        } else {
            Node* current = table[index];
            while (current->next != nullptr) {
                current = current->next;
            }
            current->next = newNode;
        }
    }

    // Search for a value by key
    int search(std::string key) {
        int index = hashFunction(key);
        Node* current = table[index];
        while (current != nullptr) {
            if (current->key == key) {
                return current->value;
            }
            current = current->next;
        }
        return -1; // Return -1 if key not found
    }

    // Delete a key-value pair from the hash table
    void deleteKey(std::string key) {
        int index = hashFunction(key);
        Node *current = table[index], *prev = nullptr;
        while (current != nullptr) {
            if (current->key == key) {
                if (prev == nullptr) {
                    table[index] = current->next; // Remove head
                } else {
                    prev->next = current->next; // Remove from between or end
                }
                delete current;
                return;
            }
            prev = current;
            current = current->next;
        }
    }

    // Display the hash table
    void display() {
        for (int i = 0; i < capacity; i++) {
            Node* current = table[i];
            std::cout << "Bucket " << i << ": ";
            while (current != nullptr) {
                std::cout << "[" << current->key << " : " << current->value << "] -> ";
                current = current->next;
            }
            std::cout << "nullptr" << std::endl;
        }
    }
};

int main() {
    HashTable ht(10);
    ht.insert("name", 1);
    ht.insert("age", 25);
    ht.insert("address", 100);
    ht.insert("phone", 123456);
    ht.display();

    std::cout << "The value for 'name' is: " << ht.search("name") << std::endl;
    ht.deleteKey("age");
    std::cout << "After deleting 'age':" << std::endl;
    ht.display();
    return 0;
}
