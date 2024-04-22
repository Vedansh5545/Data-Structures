/*
implementation of Quadratic Probing in C++ using hash table and hash function Mid-square base 10 Hashing for integer keys
*/
#include <iostream>
#include <vector>
#include <string>
#include <cmath>
using namespace std;

class QuadraticProbing {
    private:
        int capacity;
        int size;
        int prime;
        vector<string> hashTable;
    public:
        QuadraticProbing(int c);
        int hash(int key);
        int nextPrime(int n);
        bool isPrime(int n);
        void insertItem(int key);
        void deleteItem(int key);
        void displayHash();
        void search(int key);
};