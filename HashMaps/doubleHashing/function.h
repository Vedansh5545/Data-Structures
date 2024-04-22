/*
Implement Double-Hashing in replacement
*/

#include <iostream>
#include <vector>
#include <string>
#include <cmath>

using namespace std;

class DoubleHashing {
    private:
        int capacity;
        int size;
        int prime;
        vector<int> hashTable;
    public:
        DoubleHashing(int c);
        int hash(int key);
        int hash1(int key);
        int hash2(int key);
        int nextPrime(int n);
        bool isPrime(int n);
        void insertItem(int key);
        void deleteItem(int key);
        void displayHash();
        void search(int key);
};
