#include<iostream>
#include<list>
#include<string>

using namespace std;

/* This is a simple hash table implementation using separate chaining
    to handle collisions. The hash table uses a vector of lists to store
    the key-value pairs. The hash function is a simple modulo operation
    based on the size of the table. */
// Implemented by  Himaja Kakade 2025

class HashTable {
    private:
        static const int hashGroups = 10; // Number of buckets in the hash table
        list<pair<int, string>> table[hashGroups];
    
    public:
        bool isEmpty() const;
        int hashFunction(int key);
        void insertItem(int key, string value);
        void removeItem(int key);
        string searchTable(int key);
        void printTable();

    };


bool HashTable::isEmpty() const{
    int sum{};
    for(int i{}; i < hashGroups; i++){
        sum += table[i].size();
    }

    if (!sum) {
        return true;
    }

    return false;
}

int HashTable::hashFunction(int key) {
    return key % hashGroups; //Key: 101, this function will return 1
}

void HashTable::insertItem(int key, string value) {
    int hashValue = hashFunction(key);
    auto& cell = table[hashValue];
    auto bItr = begin(cell);
    bool keyExists = false;

    for(; bItr != end(cell); bItr++) {
        if(bItr->first == key) {
            keyExists = true;
            bItr->second = value;
            cout << "[WARNING] Key exists. Value replaced" << endl;
            break;
        }
    }

    if (!keyExists) {
        cell.emplace_back(key, value);
    }

    return;
}

void HashTable::removeItem(int key) {
    int hashValue = hashFunction(key);
    auto& cell = table[hashValue];
    auto bItr = begin(cell);
    bool keyExists = false;

    for(; bItr != end(cell); bItr++) {
        if(bItr->first == key) {
            keyExists = true;
            bItr = cell.erase(bItr);
            cout << "[INFO] Item removed" << endl;
            break;
        }
    }

    if (!keyExists) {
        cout << "[WARNING] Key not found." << endl;
    }
}

void HashTable::printTable() {
    for (int i{}; i < hashGroups; i++){
        if(table[i].size() == 0) continue;

        auto bItr = table[i].begin();
        for(; bItr != table[i].end(); bItr++){
            cout << "[INFO] Key: " << bItr->first << "Value: " << bItr->second << endl;
        }
    }

    return;
}

string HashTable::searchTable(int key) {
    int hashValue = hashFunction(key);
    auto& cell = table[hashValue];
    auto bItr = begin(cell);
    bool keyExists = false;

    for(; bItr != end(cell); bItr++) {
        if(bItr->first == key){
            keyExists = true;
            return "Key found. Value: " + bItr->second;
        }
    }

    if(!keyExists) {
        return "Key not found";
    }

    return "";
}

int main() {
    HashTable HT;

    if(HT.isEmpty()) {
        cout << "Correct answer! Good job." << endl;
    } else {
        cout << "[WARNING] Check the code!" << endl;
    }

    HT.insertItem(382, "Himaja");
    HT.insertItem(293, "John");
    HT.insertItem(102, "Sally");
    HT.insertItem(931, "Herbert");
    HT.insertItem(200, "Tom");
    HT.insertItem(190, "Kelly");
    HT.insertItem(482, "Jim");
    HT.insertItem(185, "Sam");
    HT.insertItem(185, "Rob");

    HT.printTable();

    HT.removeItem(102);
    HT.removeItem(100);
    if(HT.isEmpty()) {
        cout << "[WARNING] Check the code!" << endl;
    } else {
        cout << "Correct answer! Good job." << endl;
    }

    string searchResult = HT.searchTable(382);
    cout << searchResult << endl;
}