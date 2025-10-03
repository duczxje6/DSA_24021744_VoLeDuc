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
}
