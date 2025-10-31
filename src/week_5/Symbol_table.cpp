#include <iostream>
#include <vector>
#include <algorithm>
#include <stdexcept>
#include <string>

using namespace std;
template <class Key, class Value>
class Symbol_table {
private:
    vector<Key> keys;  
    vector<Value> vals; 
    
    int find_rank(const Key& key) const {
        int low = 0;
        int high = keys.size() - 1;
        int rank = keys.size(); // Trường hợp key lớn hơn tất cả

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (key <= keys[mid]) {
                rank = mid; 
                high = mid - 1;
            } else {
                low = mid + 1; 
            }
        }
        return rank;
    }
public:
    bool isEmpty() const { // O(1)
        return keys.empty();
    }

    int size() const { // O(1)
        return keys.size();
    }
    void put(const Key& key, const Value& val) {
        int i = find_rank(key);
        if (i < keys.size() && keys[i] == key) {
            vals[i] = val;
            return;
        }
        
        keys.insert(keys.begin() + i, key);
        vals.insert(vals.begin() + i, val);
    }
    bool contains(const Key& key) const {
        int i = find_rank(key);
        return i < keys.size() && keys[i] == key;
    }
    Value get(const Key& key) const {
        int i = find_rank(key);
        
        if (i < keys.size() && keys[i] == key) {
            return vals[i];
        }
        
        cout<< "Key not found: " << key << endl;
        throw std::out_of_range("Key not found in Symbol Table.");
    }
    void deleteKey(const Key& key) {
        int i = find_rank(key);
        
        if (i < keys.size() && keys[i] == key) {
            keys.erase(keys.begin() + i);
            vals.erase(vals.begin() + i);
        }
    }
    Key min() const { 
        if (isEmpty()) throw std::out_of_range("Symbol Table is empty.");
        return keys.front();
    }
    Key max() const { 
        if (isEmpty()) throw std::out_of_range("Symbol Table is empty.");
        return keys.back();
    }
    Key floor(const Key& key) const {
        int i = find_rank(key); 

        if (i < keys.size() && keys[i] == key) {
            return keys[i]; 
        }
        
        if (i == 0) {
            throw std::out_of_range("No key less than or equal to floor key.");
        }
        
        return keys[i - 1]; 
    } 
    Key ceiling(const Key& key) const {
        int i = find_rank(key); 

        if (i < keys.size()) {
            return keys[i]; 
        }
        
        throw std::out_of_range("No key greater than or equal to ceiling key.");
    }
    int rank(const Key& key) const { 
        return find_rank(key);
    }
    Key select(int k) const {
        if (k < 0 || k >= size()) {
            throw std::out_of_range("Rank k is out of bounds.");
        }
        return keys[k];
    }
    
    void deleteMin() { // O(N)
        if (!isEmpty()) {
            keys.erase(keys.begin());
            vals.erase(vals.begin());
        }
    }
    
    void deleteMax() { // O(1)
        if (!isEmpty()) {
            keys.pop_back();
            vals.pop_back();
        }
    }
    int size(const Key& lo, const Key& hi) const { 
        if (lo > hi) return 0;
        
        int start_index = find_rank(lo); 
        int low = 0;
        int high = keys.size() - 1;
        int end_index = keys.size();

        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (hi < keys[mid]) {
                end_index = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        
        return end_index - start_index;
    }
    vector<Key> keys_in_range(const Key& lo, const Key& hi) const {
        vector<Key> rangeKeys;
        
        int start_index = find_rank(lo);
        
        for (int i = start_index; i < keys.size(); ++i) {
            if (keys[i] > hi) {
                break;
            }
            rangeKeys.push_back(keys[i]);
        }
        return rangeKeys;
    }
    const vector<Key>& get_keys() const {
        return keys;
    }
};
int main() {
    Symbol_table<string, int> st;
    // Thao tác put (chèn/cập nhật)
    st.put("S", 0);
    st.put("E", 1);
    st.put("A", 2);
    st.put("R", 3);
    st.put("C", 4);
    st.put("H", 5);
    st.put("E", 6); // Cập nhật E (giá trị mới là 6)
    st.put("X", 7);
    
    cout << "\nKich thuoc sau khi chen: " << st.size() << endl;

    // In ra các keys đã sắp xếp
    cout << "Cac Keys hien tai (da sap xep): ";
    for (const auto& key : st.get_keys()) {
        cout << key << " ";
    }
    cout << " (Thứ tự: A C E H R S X)" << endl;

    // --- Kiem tra thao tac O(log N) ---
    cout << "\n--- Kiem tra O(log N) ---" << endl;
    try {
        cout << "Gia tri cho 'E': " << st.get("E") << endl; // 6
        cout << "Key 'Z' ton tai? " << (st.contains("Z") ? "Co" : "Khong") << endl;
        
        // Thao tac Floor/Ceiling
        cout << "Floor cua 'F' (<= 'F'): " << st.floor("F") << endl; // E
        cout << "Ceiling cua 'F' (>= 'F'): " << st.ceiling("F") << endl; // H
        
        // Thao tac Rank/Select
        cout << "Rank cua 'H' (So luong key < 'H'): " << st.rank("H") << endl; // 3 (A, C, E)
        cout << "Key tai Rank 2 (Key thu 3): " << st.select(2) << endl; // E
        
        // Thao tac Size trong khoang
        cout << "So luong key trong khoang ['C', 'S']: " << st.size("C", "S") << endl; // 5 (C, E, H, R, S)

    } catch (const std::out_of_range& e) {
        cerr << "Loi: " << e.what() << endl;
    }
    
    cout << "\n--- Kiem tra xoa (O(N)) ---" << endl;
    st.deleteMin(); // Xóa A
    st.deleteKey("R"); // Xóa R

    cout << "Kich thuoc sau khi xoa A va R: " << st.size() << endl;
    cout << "Keys con lai: ";
    for (const auto& key : st.get_keys()) {
        cout << key << " ";
    }
    cout << " (Thứ tự: C E H S X)" << endl;

    return 0;
}
