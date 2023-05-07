/*
You are asked to use C++ to implement Hash table with linear probing
    The keys are lower-case English words (e.g., apple, pear).
    The length of a key is at most 10.
    The hash function is "simply using the last character". That is, the hash value of apple should be e, and the hash value of pear should be r.
    Your hash table contains exactly 26 slots (hash value a to hash value z).
    A table slot has three different statuses: "never used", "tombstone", and "occupied". Table starts with 26 "never used" slots.

Searching works as follows:
    given a key, take its last character as the hash value. First try the corresponding table slot, if the objective key is there, then you have found it. 
    If the corresponding slot is never used, terminate because we are certain that the objective is not in the table. 
    If the slot is occupied but it's not the objective, or the slot is a \tombstone", then we move on to the next slot (may need to wrap around the table if the current slot is the last one). 
    We keep trying until we either nd the key or are certain that the key does not exist in the table.

Insertion works as follows:
    First perform searching to ensure that the key does not exist. 
    If it already exists, then do nothing. 
    If it does not, take the last character of a key as the hash value. 
    If the corresponding table slot is not occupied (either "never used" or "tombstone"), put the key there (the slot is now occupied).
    If the corresponding slot is already occupied, try the next slot. Repeat trying until you find an unoccupied slot.

Deletion works as follows:
    given a key, use the searching process to locate its slot. (If the key is not in the table, then do nothing.) 
    Once you find the key, change the slot status to "tombstone".

You should start your program by initializing an empty hash table. Your program takes one line as input. 
The input line contains n "modification moves" separated by spaces (1 <= n <= 26). The available modification moves are:
    AWord (Character A followed by a lower-case English word of length at most 10): 
    Aapple means insert key apple into the hash table. If apple is already in the table, do nothing.
    DWord (Character D followed by a lower-case English word of length at most 10): 
    Dapple means delete key apple from the hash table. If apple is not in the tree, do nothing.
    At the end, you need to go through the slots from a to z, and output all the keys separated by space.
    You don't need to worry about invalid inputs.
    
    Sample input 1: Aaaa Accc Abbb
    Sample output 1: aaa bbb ccc
    Sample input 2: Abba Aaaa Acca
    Sample output 2: bba aaa cca
    Sample input 3: Abba Aaaa Acca Daaa
    Sample output 3: bba cca
*/

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
