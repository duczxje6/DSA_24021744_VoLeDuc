#include <iostream>
using namespace std;
struct Heap {
    int size;  
    int a[] ;

    Heap() {
    size = 0;
}
    
    Heap(int n, int arr[]) {
        size = n;
        for (int i = 0; i < n; i++) {
            a[i] = arr[i];
        }
    }
    void swim(int index){
        while (index > 0){
            int parent = (index - 1) / 2;
            if (a[parent] > a[index]){
                swap(a[parent], a[index]);
                index = parent;
            } else {
                break;
            }
        }
    }
    void sink(int index){
        int left = 2 * index + 1;
        int right = 2 * index + 2;
        int largest = index;
        if (left < size && a[left] < a[largest]){
            largest = left;
        }
        if (right < size && a[right] < a[largest]){
            largest = right;
        }
        if (largest != index){
            swap(a[largest], a[index]);
            sink(largest);
        }
    }

// Hàm xuất mảng 
void printArray(int arr[], int size)
{
    for (int i=0; i < size; i++)
        cout<<arr[i]<<" ";
}


};