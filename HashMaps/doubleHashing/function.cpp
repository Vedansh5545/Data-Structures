#include "function.h"

/*
Implement Double-Hashing in replacement for int keys
*/

DoubleHashing::DoubleHashing(int c){
    capacity = c;
    size = 0;
    prime = nextPrime(c);
    hashTable.resize(capacity);
}

int DoubleHashing::hash(int key){
    int i = 0;
    while(true){
        int index = (hash1(key) + i * hash2(key)) % capacity;
        if(hashTable[index] == 0){
            return index;
        }
        i++;
    }
}

int DoubleHashing::hash1(int key){
    return key % capacity;
}

int DoubleHashing::hash2(int key){
    return prime - (key % prime);
}

int DoubleHashing::nextPrime(int n){
    if(n <= 1){
        return 2;
    }
    int prime = n;
    bool found = false;
    while(!found){
        prime++;
        if(isPrime(prime)){
            found = true;
        }
    }
    return prime;
}

bool DoubleHashing::isPrime(int n){
    if(n <= 1){
        return false;
    }
    if(n <= 3){
        return true;
    }
    if(n % 2 == 0 || n % 3 == 0){
        return false;
    }
    for(int i = 5; i * i <= n; i += 6){
        if(n % i == 0 || n % (i + 2) == 0){
            return false;
        }
    }
    return true;
}

void DoubleHashing::insertItem(int key){
    if(size == capacity){
        std::cout << "No slots are empty. Hash Table is full." << std::endl;
        return;
    }
    int index = hash(key);
    if(hashTable[index] != 0){
        int index2 = hash2(key);
        int i = 1;
        while(true){
            int newIndex = (index + i * index2) % capacity;
            if(hashTable[newIndex] == 0){
                hashTable[newIndex] = key;
                break;
            }
            i++;
        }
    }
    else{
        hashTable[index] = key;
    }
    size++;
}

void DoubleHashing::deleteItem(int key){
    int index = hash(key);
    if(hashTable[index] == key){
        hashTable[index] = 0;
        size--;
        return;
    }
    int index2 = hash2(key);
    int i = 1;
    while(true){
        int newIndex = (index + i * index2) % capacity;
        if(hashTable[newIndex] == key){
            hashTable[newIndex] = 0;
            size--;
            return;
        }
        if(hashTable[newIndex] == 0){
            cout << "Element not found" << endl;
            return;
        }
        i++;
    }
    
}

void DoubleHashing::displayHash(){
    for(int i = 0; i < capacity; i++){
        if(hashTable[i] != 0){
            cout << i << " --> " << hashTable[i] << endl;
        }
        else{
            cout << i << endl;
        }
    }
}


void DoubleHashing::search(int key){
    int index = hash(key);
    if(hashTable[index] == key){
        cout << key << " is found at index " << index << endl;
        return;
    }
    int index2 = hash2(key);
    int i = 1;
    while(true){
        int newIndex = (index + i * index2) % capacity;
        if(hashTable[newIndex] == key){
            cout << key << " is found at index " << newIndex << endl;
            return;
        }
        if(hashTable[newIndex] == 0){
            cout << key << " is not found in the hash table" << endl;
            return;
        }
        i++;
    }
}

