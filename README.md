# Hash-table-with-linear-probing
/*
You are tasked with implementing a hash table using linear probing. The keys are lowercase English words, each of which has a length of at most 10 characters. The hash function is straightforward - it uses the last character of the word as the hash value. For instance, the word "apple" would be hashed to the slot corresponding to the character 'e', and "pear" would be hashed to the slot corresponding to 'r'. The hash table has exactly 26 slots, corresponding to the 26 letters of the English alphabet.

Each slot in the hash table can have one of three statuses: "never used", "tombstone", or "occupied". Initially, all slots are set to the "never used" status.

Searching in the hash table works as follows:

Given a key, you calculate its hash value by taking the last character.
You start by checking the corresponding slot.
If the key is found in that slot, the search is successful.
If the slot is "never used", you can conclude that the key is not in the table.
If the slot is occupied by a different key or is a "tombstone", you move on to the next slot (possibly wrapping around to the beginning of the table). You continue this process until you find the key or determine that it's not present.
Insertion in the hash table works as follows:

Before inserting a key, you perform a search to make sure it's not already present in the table.
If the key is already there, you do nothing.
If the key is not found, you calculate its hash value.
If the corresponding slot is unoccupied (either "never used" or a "tombstone"), you place the key in that slot, marking it as "occupied".
If the slot is occupied, you move to the next slot and repeat the process until you find an unoccupied slot.
Deletion in the hash table works as follows:

To delete a key, you use the search process to locate its slot.
If the key is not found, you do nothing.
If the key is found, you change the slot's status to "tombstone".
Your program starts by initializing an empty hash table. It then takes a single line of input containing n "modification moves" separated by spaces (1 <= n <= 26). The possible modification moves are:

AWord (Character 'A' followed by a lowercase English word): This means you insert the key into the hash table.
DWord (Character 'D' followed by a lowercase English word): This means you delete the key from the hash table.
At the end of the program, you need to iterate through the slots from 'a' to 'z' and output all the keys separated by spaces.
You can assume that the inputs will be valid. Your task is to implement the described hash table operations and output the final state of the hash table
    
    Sample input 1: Aaaa Accc Abbb
    Sample output 1: aaa bbb ccc
    Sample input 2: Abba Aaaa Acca
    Sample output 2: bba aaa cca
    Sample input 3: Abba Aaaa Acca Daaa
    Sample output 3: bba cca
*/
