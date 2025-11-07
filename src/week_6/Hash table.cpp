#include <iostream>
#include <vector>

using namespace std;

struct HashNode {
    string key;
    int value;
    HashNode* next;

    HashNode(const string& k, int v) : key(k), value(v), next(nullptr) {}
};
class HashTable {
private:
    static const int TABLE_SIZE = 101;
    HashNode** table;       
public:
    HashTable() {
        table = new HashNode * [TABLE_SIZE];
        for (int i = 0; i < TABLE_SIZE; ++i) {
            table[i] = nullptr;
        }   
    }
    ~HashTable() {
        for (int i = 0; i < TABLE_SIZE; ++i) {
            HashNode* entry = table[i];
            while (entry != nullptr) {
                HashNode* prev = entry;
                entry = entry->next;
                delete prev;
            }
        }
        delete[] table;
    }
    int hashFunction(const string& key) const {
        unsigned long hash = 5381;
        for (char c : key) {
            hash = ((hash << 5) + hash) + c; 
        }
        return hash % TABLE_SIZE;
    }           

  