#include "Quadratic Probing.h"

/*
implementation of Quadratic Probing in C++ using hash table and hash function Mid-square base 10 Hashing for integer keys
*/

QuadraticProbing::QuadraticProbing(int c){
    capacity = c;
    size = 0;
    prime = nextPrime(c);
    hashTable.resize(capacity);
}

int QuadraticProbing::hash(int key){
    int square = key * key;
    int numDigits = 0;
    int temp = key;
    while(temp != 0){
        numDigits++;
        temp /= 10;
    }
    int shift = (numDigits - capacity) / 2;
    int shiftedSquare = square / pow(10, shift);
    int hashedKey = shiftedSquare % capacity;
    return hashedKey;
}


int QuadraticProbing::nextPrime(int n){
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


bool QuadraticProbing::isPrime(int n){
    if(n <= 1){
        return false;
    }
    if(n <= 3){
        return true;
    }
    if(n % 2 == 0 || n % 3 == 0){
        return false;
    }
    for(int i = 5; i * i <= n; i = i + 6){
        if(n % i == 0 || n % (i + 2) == 0){
            return false;
        }
    }
    return true;
}

void QuadraticProbing::insertItem(int key){
    if(size == capacity){
        cout << "Hash Table is full" << endl;
        return;
    }
    int index = hash(key);
    int

    count = 0;
    while(hashTable[index] != "" && hashTable[index] != "DELETED"){
        index = (index + count * count) % capacity;
        count++;
    }
    hashTable[index] = to_string(key);
    size++;
    cout << "Key " << key << " inserted" << endl;
}

void QuadraticProbing::deleteItem(int key){
    int index = hash(key);
    int count = 0;
    while(hashTable[index] != ""){
        if(hashTable[index] == to_string(key)){
            hashTable[index] = "DELETED";
            size--;
            cout << "Key " << key << " deleted" << endl;
            return;
        }
        index = (index + count * count) % capacity;
        count++;
    }
    cout << "Key " << key << " not found" << endl;
}

void QuadraticProbing::displayHash(){
    for(int i = 0; i < capacity; i++){
        if(hashTable[i] != ""){
            cout << "Index " << i << ": " << hashTable[i] << endl;
        }
    }
}

void QuadraticProbing::search(int key){
    int index = hash(key);
    int count = 0;
    while(hashTable[index] != ""){
        if(hashTable[index] == to_string(key)){
            cout << "Key " << key << " found" << endl;
            return;
        }
        index = (index + count * count) % capacity;
        count++;
    }
    cout << "Key " << key << " not found" << endl;
}

