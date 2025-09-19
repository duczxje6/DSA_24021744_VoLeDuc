#include <iostream>
using namespace std;
struct List {
    int size;  
    int a[] ;

    // Truy cập
    int Search (int index){
        return a[index] ;
    }

    // Chèn phần tử vào đầu
    void insertF (int data){
        size += 1;
        for(int i=0; i<size-1; i++){
            a[i+1] = a[i];
        }
        a[0] = data;
    }

    // Chèn phần tử vào cuối
    void insertL (int data){
        size += 1;
        a[size-1] = data;
    }

    // Chèn vào vị trí i 
    void insert (int data, int index){
        size += 1;
        for (int i=size-2; i>index ;i--){
            a[i+1] = a[i];
        }
        a[index] = data;
    }

    // Xóa phần tử đầu
    void deleteF (){
        for (int i=size-1; i>0; i--){
            a[i-1] = a[i];
        }
        size--; 
    }

    // Xóa phần tử cuối
    void deleteL (){
        size--; 
    }

    // Xóa vị trí i
    void deletE (int index){
        for (int i=size-1; i>index; i--){
            a[i-1] = a[i];
        }
        size--;
    }

    // Duyệt xuôi
    void printF (){
        for(int i=0; i<=size-1; i++){
            cout<<a[i]<<" "; 
        }
    }

    // Duyệt ngược
    void printB(){
        for(int i=size-1; i>=0; i--){
            cout<<a[i]<<" ";
        }
    }
};
int main() {
    List l; 
    l.size = 0;
    cout<<"size = ";
    cin >> l.size ;
    l.insertF(7) ;
    l.insertF(0) ;
    l.insertF(5) ;
    l.insertF(3) ;
    l.insertF(1) ;
    cout << "Duyet xuoi: ";
    l.printF(); cout << endl;

    return 0;
   

}