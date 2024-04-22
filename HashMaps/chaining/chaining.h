
#include <iostream>
#include <vector>
#include <list>
#include <string>
#include <cmath>

using namespace std;

class HashMap {
    private:
        vector<list<int> > table;
        int bucketSize;
        int hash(int key);
    public:
        HashMap(int b);
        void insertItem(int key);
        void deleteItem(int key);
        int searchItem(int key);
        void display();
};