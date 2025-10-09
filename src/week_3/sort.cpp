#include <iostream>
using namespace std;

// Selection Sort

void swap(int &x, int &y) // Hàm đổi chỗ 2 số nguyên
{
    int temp = x;
    x = y;
    y = temp;
}

void selectionSort(int arr[], int n)
{
    int i, j, min_idx;
    // Di chuyển ranh giới của mảng đã sắp xếp và chưa sắp xếp
    for (i = 0; i < n-1; i++)
    {
	// Tìm phần tử nhỏ nhất trong mảng chưa sắp xếp
	min_idx = i;
	for (j = i+1; j < n; j++)
	    if (arr[j] < arr[min_idx])
		min_idx = j;

	// Đổi chỗ phần tử nhỏ nhất với phần tử đầu tiên
        swap(arr[min_idx], arr[i]);
    }
}


// Bubble Sort
void bubbleSort(int arr[], int n)
{
    int i, j;
    bool haveSwap = false;
    for (i = 0; i < n-1; i++){
    // i phần tử cuối cùng đã được sắp xếp
        haveSwap = false;
        for (j = 0; j < n-i-1; j++){
            if (arr[j] > arr[j+1]){
                swap(arr[j], arr[j+1]);
                haveSwap = true; // Kiểm tra lần lặp này có swap không
            }
        }
        // Nếu không có swap nào được thực hiện => mảng đã sắp xếp. Không cần lặp thêm
        if(haveSwap == false){
            break;
        }
    }
}


// Insertion Sort
void insertionSort(int arr[], int n)
{
   int i, key, j;
   for (i = 1; i < n; i++)
   {
       key = arr[i];
       j = i-1;
 
       /* Di chuyển các phần tử có giá trị lớn hơn giá trị 
       key về sau một vị trí so với vị trí ban đầu
       của nó */
       while (j >= 0 && arr[j] > key)
       {
           arr[j+1] = arr[j];
           j = j-1;
       }
       arr[j+1] = key;
   }
}
// Binary search
int binarySearch(int arr[], int l, int r, int x) {
  if (r >= l) {
    int mid = l + (r-1) / 2; // Tương đương (l+r)/2 nhưng ưu điểm tránh tràn số khi l,r lớn

    // Nếu arr[mid] = x, trả về chỉ số và kết thúc.
    if (arr[mid] == x)
      return mid;

    // Nếu arr[mid] > x, thực hiện tìm kiếm nửa trái của mảng
    if (arr[mid] > x)
      return binarySearch(arr, l, mid - 1, x);

    // Nếu arr[mid] < x, thực hiện tìm kiếm nửa phải của mảng
    return binarySearch(arr, mid + 1, r, x);
  }

  // Nếu không tìm thấy
  return -1;
}
// Merge Sort      O[nlogn]
struct Item {
    int key;


// Hàm trộn 2 mảng con đã sắp xếp: A[a..c], A[c+1..b]
void Merge(Item A[], int a, int c, int b) {
    int i = a;
    int j = c + 1;
    int k = 0;
    int n = b - a + 1;

    Item* B = new Item[n];  // mảng tạm để chứa kết quả trộn

    // Trộn hai nửa
    while (i < c + 1 && j < b + 1) {
        if (A[i].key < A[j].key)
            B[k++] = A[i++];
        else
            B[k++] = A[j++];
    }

    // Sao chép phần còn lại của nửa 1
    while (i < c + 1)
        B[k++] = A[i++];

    // Sao chép phần còn lại của nửa 2
    while (j < b + 1)
        B[k++] = A[j++];

    // Ghi ngược kết quả về lại A
    i = a;
    for (k = 0; k < n; k++)
        A[i++] = B[k];

    delete[] B;
}

void MergeSort(Item A[], int a, int b)
{
    if (a<b){
        int c = (a+b)/2;
        MergeSort(A, a, c);
        MergeSort(A, c+1, b);
        Merge(A, a, c, b);
    }
}
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

void print(Item A[], int n) {
    for (int i = 0; i < n; i++)
        cout << A[i].key << " ";
    cout << endl;
}


// Heap sort       O[nlogn]
// Hàm ShiftDown: Duy trì tính chất heap cho cây con có gốc tại a
void ShiftDown(Item A[], int a, int b)
{
    int i = a;
    int j = 2 * i + 1;   // con trái
    while (j <= b)
    {
        int k = j + 1;   // con phải
        if (k <= b && A[k].key < A[j].key)
            j = k;       // chọn con nhỏ hơn
        if (A[i].key > A[j].key)
        {
            swap(A[i], A[j]);
            i = j;
            j = 2 * i + 1;
        }
        else break;
    }
}

// Hàm HeapSort
void HeapSort(Item A[], int n)
{
    //  Xây dựng heap ban đầu
    for (int i = n / 2 - 1; i >= 0; i--)
        ShiftDown(A, i, n - 1);

    //  Trích phần tử nhỏ nhất dần dần
    for (int i = n - 1; i >= 1; i--)
    {
        swap(A[0], A[i]);
        ShiftDown(A, 0, i - 1);
    }
}

};

// Hàm xuất mảng 
void printArray(int arr[], int size)
{
    for (int i=0; i < size; i++)
        cout<<arr[i]<<" ";
}
int main() {
    int arr[] = {64, 25, 12, 22, 11};
    int n = sizeof(arr)/sizeof(arr[0]);

    cout << "Mang ban dau: ";
    printArray(arr, n); cout<<endl;

    // Test Selection Sort
    int arr1[5] = {64, 25, 12, 22, 11};
    selectionSort(arr1, n);
    cout << "Sau Selection Sort: ";
    printArray(arr1, n); cout<<endl;

    // Test Bubble Sort
    int arr2[5] = {64, 25, 12, 22, 11};
    bubbleSort(arr2, n);
    cout << "Sau Bubble Sort: ";
    printArray(arr2, n); cout<<endl;

    // Test Insertion Sort
    int arr3[5] = {64, 25, 12, 22, 11};
    insertionSort(arr3, n);
    cout << "Sau Insertion Sort: ";
    printArray(arr3, n); cout<<endl;

    return 0;



    int arr[] = {45, 12, 7, 23, 89, 34, 2, 17};
    int n = sizeof(arr) / sizeof(arr[0]);
    Item it;
    // Chuyển sang mảng Item
    Item A1[100], A2[100], A3[100];
    for (int i = 0; i < n; i++) {
        A1[i].key = arr[i];
        A2[i].key = arr[i];
        A3[i].key = arr[i];
    }

    cout << "Mang ban dau: ";
    it.print(A1, n);

    // Merge Sort
    it.MergeSort(A1, 0, n - 1);
    cout << "Sau Merge Sort: ";
    it.print(A1, n);

    // Quick Sort
    it.QuickSort(A2, 0, n - 1);
    cout << "Sau Quick Sort: ";
    it.print(A2, n);

    // Heap Sort
    it.HeapSort(A3, n);
    cout << "Sau Heap Sort: ";
    it.print(A3, n);

    return 0;

}
