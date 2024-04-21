/*
implement hash map using chaining coliision strategy and Multiplicative String Hash function bucket size is 12 and key is integer
*/
#include "chaining.h"

HashMap::HashMap(int b) {
    bucketSize = b;
    table.resize(bucketSize);
}

int HashMap::hash(int key) {
    return key % bucketSize;
}

void HashMap::insertItem(int key) {
    int index = hash(key);
    table[index].push_back(key);
}

void HashMap::deleteItem(int key) {
    int index = hash(key);
    list<int>::iterator i;
    for (i = table[index].begin(); i != table[index].end(); i++) {
        if (*i == key) {
            break;
        }
    }
    if (i != table[index].end()) {
        table[index].erase(i);
    }
}

int HashMap::searchItem(int key) {
    int index = hash(key);
    list<int>::iterator i;
    for (i = table[index].begin(); i != table[index].end(); i++) {
        if (*i == key) {
            return index;
        }
    }
    return -1;
}

void HashMap::display() {
    for (int i = 0; i < bucketSize; i++) {
        cout << i;
        for (auto x : table[i]) {
            cout << " --> " << x;
        }
        cout << endl;
    }
}


