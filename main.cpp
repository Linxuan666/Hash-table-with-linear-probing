#include <iostream>
#include <string>
#include <sstream>
using namespace std;

// Node for storing key and status
struct Slot {
    string key;
    string status;
};

// define hash table with linear probing
class HashTable {
private:
    Slot table[26];                         // array of Nodes
    int hash(string key);                   // hash function
public:
    HashTable();                            // construct table starts with 26 "never used" slots.
    int search(string key);                 // search function
    void insert(string key);                // insert function
    void deletion(string key);              // delete function
    void output();                           // print function
};

// hash function
int HashTable::hash(string key) {                 
    return key[key.length() - 1] - 'a';
}

// construct table starts with 26 "never used" slots.
HashTable::HashTable() {               
    for (int i = 0; i < 26; i++) {
        table[i].status = "never used";
    }
}

// search function
int HashTable::search(string key) {         
    int value = hash(key);
    int i = value;
    do {
        if (table[i].status == "never used") {
            return -1;
        }
        if (table[i].status == "occupied" && table[i].key == key) {
            return i;
        }
        i = (i + 1) % 26;
    } while (i != value);
    return -1;
}

// insert function
void HashTable::insert(string key) {            
    if (search(key) != -1) {                        // key already exists
        return;
    }
    int value = hash(key);
    int i = value;
    do {
        if (table[i].status != "occupied") {
            table[i].key = key;
            table[i].status = "occupied";
            break;
        }
        i = (i + 1) % 26;
    } while (i != value);                           // table is full                        
}

// delete function
void HashTable::deletion(string key) {                        
    if (search(key) == -1) {                        // not in the table
        return;
    }
    int value = hash(key);
    int i = value;
    do {
        if (table[i].status == "occupied" && table[i].key == key) {
            table[i].status = "tombstone";
        }
        i = (i + 1) % 26;
    } while (i != value);                       
}
void HashTable::output() {                           // print function
    for (int i = 0; i < 26; i++) {
        if (table[i].status == "occupied") {
            cout << table[i].key << " ";
        }
    }
}

int main() {
    HashTable h;
    string input;
    getline(cin, input);
    stringstream ss(input);
    string word;
    while (ss >> word) {
        string key = word.substr(1);
        if (word[0] == 'A') {
            h.insert(key);
        }
        else if (word[0] == 'D') {
            h.deletion(key);
        }
    }
    h.output();
    return 0;
}
