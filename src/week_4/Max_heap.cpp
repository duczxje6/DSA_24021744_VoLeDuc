#include <iostream>
#include <vector>
using namespace std;
struct Heap {
    int size;              // số phần tử hiện có trong heap
    vector<int> a;         // mảng chứa dữ liệu của heap

    // Constructor mặc định
    Heap() {
        size = 0;
    }

    // Constructor có tham số: tạo heap từ mảng có sẵn
    Heap(int n, int arr[]) {
        size = n;
        a.assign(arr, arr + n);   // sao chép arr[] vào vector a
    }
    void swim(int index){              // O[logn]
        while (index > 0){
            int parent = (index - 1) / 2;
            if (a[parent] < a[index]){      //so sánh 2 GT cha và ptu đang xét
                swap(a[parent], a[index]);  // thỏa mãn thì swap
                index = parent;             // thay GT cha
            } else {
                break;
            }
        }
    }
    void sink(int index){               //O[logn]
        int left = 2 * index + 1;
        int right = 2 * index + 2;
        int max = index;                // gán vị trí max = vị trí index đang xét
        if (left < size && a[left] > a[max]){   
            max = left;                 // gán tạm thời vtri max = left
        }
        if (right < size && a[right] > a[max]){
            max = right;                // nếu thỏa mãn thay vtri max = right
        }
        if (max != index){             
            swap(a[max], a[index]);     // thay đổi vị trí
            sink(max);                  // gọi lại đệ quy hàm sink cho GT max
        }
    }

// Hàm xuất mảng 
void printArray()
{
    for (int i=0; i < size; i++)
        cout<<a[i]<<" ";
}


};
struct Priority_Queue{
    Heap heap;
    
    // Hàm check
    bool isEmpty(){
        return heap.size == 0;
    }

    // size
    int size(){
        return heap.size;
    }

    void insert(int data){
        heap.size++ ; 
        heap.a[heap.size-1] = data;
        heap.swim(heap.size-1) ;
    }

    int max(){
        return heap.a[0];
    }

    int delMax(){
        heap.sink(heap.a[0]);
        heap.size--;
    }
    void print(){
        heap.printArray();
    }
};

int main() {
    Priority_Queue pq;

    // Thêm phần tử vào heap
    pq.insert(30);
    pq.insert(10);
    pq.insert(50);
    pq.insert(20);
    pq.insert(40);

    cout << "Heap sau khi chen: ";
    pq.print();

    cout << "Phan tu lon nhat: " << pq.max() << endl;

    cout << "Xoa max: " << pq.delMax() << endl;

    cout << "Heap sau khi xoa: ";
    pq.print();

    return 0;
}