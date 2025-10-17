#include <iostream>
using namespace std;
#include <vector>
template <class Key, class Value>
class Symbol_table{
private:
    vector<Key> keys; // Mảng chứa các ký hiệu
    vector<Value> vals; // Mảng chứa các giá trị tương ứng
public:
    bool isEmpty(){ // Kiểm tra bảng ký hiệu có rỗng không
        return keys.size() == 0;
    }
    struct Item{
        int key;
// Quick Sort      O[nlogn] 
void Partition(Item A[], int a, int b, int &k) {
    int pivot = A[a].key;
    int left = a + 1;
    int right = b;

    do {
        while ((left <= right) && (A[left].key <= pivot))
            left++;
        while ((left <= right) && (A[right].key > pivot))
            right--;
        if (left < right) {
            swap(A[left], A[right]);
            left++;
            right--;
        }
    } while (left <= right);

    swap(A[a], A[right]);
    k = right;
}

void QuickSort(Item A[], int a, int b) {
    if (a < b) {
        int k;
        Partition(A, a, b, k);
        if (a <= k - 1)
            QuickSort(A, a, k - 1);
        if (k + 1 <= b)
            QuickSort(A, k + 1, b);
    }
}
    }
    
       
    // Hàm thêm ký hiệu mới
    void put(Key key, Value val){
        keys.push_back(key);
        vals.push_back(val);    
    }
    bool contains(Key key){ // Kiểm tra ký hiệu có tồn tại không
        for(int i = 0; i < keys.size(); i++){
            if(keys[i] == key){
                return true;
            }
        }
        return false;
    }
    Value get(Key key){ // Lấy giá trị tương ứng với ký hiệu
            if(contains(key)){
                return vals[i];
            }
        return Value() // Trả về giá trị mặc định nếu không tìm thấy 
    }
    void deleteKey(Key key){ // Xóa ký hiệu và giá trị tương ứng
        for(int i = 0; i < keys.size(); i++){
            if(keys[i] == key){
                keys.erase(keys.begin() + i);
                vals.erase(vals.begin() + i);
                return;
            }
        }
    }
    int size(){ // Trả về số lượng ký hiệu trong bảng
        return keys.size();
    }
    Key min(){
        Key min = keys[0];
        for(int i = 1; i < keys.size(); i++){
            if(keys[i] < min){
                min = keys[i];  
    }
        }
        return min; 
    }
    Key max(){  
        Key max = keys[0];
        for(int i = 1; i < keys.size(); i++){
            if(keys[i] > max){
                max = keys[i];  
            }
        }
        return max; 
    }
    Key floor(Key key){        // lon nhat be hon hoac bang key
        Key floor = keys[0];
        for(int i = 0; i < keys.size(); i++){
            if(keys[i] <= key && keys[i] > floor){
                floor = keys[i];  
            }
        }
        return floor; 
    }       
    Key ceiling(Key key){       // nho nhat lon hon hoac bang key
        Key ceiling = keys[0];
        for(int i = 0; i < keys.size(); i++){
            if(keys[i] >= key && keys[i] < ceiling){   
                ceiling = keys[i];  
            }
        }
        return ceiling; 
    }
    int rank(Key key){           //ý tưởng binary search
        int rank = 0;
        for(int i = 0; i < keys.size(); i++){
            if(keys[i] < key){
                rank++;  
            }
        }
        return rank; 
    }
    key select(int k){
        return keys[k];
    }
    void deleteMin(){
        Key minKey = min();
        deleteKey(minKey);
    }
    void deleteMax(){
        Key maxKey = max();
        deleteKey(maxKey);
    }
    int size(Key lo, Key hi){   
        int count = 0;
        for(int i = 0; i < keys.size(); i++){
            if(keys[i] >= lo && keys[i] <= hi){
                count++;  
            }
        }
        return count; 
    }
    Iterable<Key> keys(Key lo, Key hi){
        vector<Key> rangeKeys;
        for(int i = 0; i < keys.size(); i++){
            if(keys[i] >= lo && keys[i] <= hi){
                rangeKeys.push_back(keys[i]);  
            }
        }
        return rangeKeys; 
    }
    Iterable<Key> keys(){       
        return keys; 
    }
};

    
