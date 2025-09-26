#include <iostream>
using namespace std;
struct List {
    int size;  
    int a[100] ;

    // Truy cập
    int search (int index){
        return a[index] ;       // O[1]
    }

    // Chèn phần tử vào đầu
    void insertF (int data){
        size += 1;
        for(int i=size-1; i>=0; i--){
            a[i+1] = a[i];
        }
        a[0] = data;            // O[n]
    }

    // Chèn phần tử vào cuối
    void insertL (int data){
        size += 1;
        a[size-1] = data;       // O[1]
    }

    // Chèn vào vị trí i 
    void insert (int data, int index){
        size += 1;
        for (int i=size-2; i>=index ;i--){
            a[i+1] = a[i];
        }
        a[index] = data;        // O[]
    }

    // Xóa phần tử đầu
    void deleteF (){
        for (int i=size-1; i>0; i--){
            a[i-1] = a[i];
        }
        size--; 
    }

    // Xóa phần tử cuối
    int deleteL (){
         return a[size-1];
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
struct Stack {
    List list;

    void Push(int item){
        list.insertL(item);
    }
    int pop(){
       return list.deleteL(); // xóa cuối trả về phần tử cuối   
    }
    int top(){
        return list.search(list.size);
    }

};
struct Queue {
    List list;
    void enqueue (int item){
        list.insertF(item);
    }
    int dequeue (){
        return list.deleteL();
    }

};
int main() { 
    List l; 
    l.size = 0;
    l.insertF(7) ;
    l.insertF(0) ;
    l.insertF(5) ;
    l.insertF(3) ;
    l.insertF(1) ;
    cout << "Duyet xuoi: ";
    l.printF(); cout << endl;
    cout << "Duyet nguoc: ";
    l.printB(); cout << endl;

    l.insertL(9);
    cout << "Duyet xuoi sau khi them 9 cuoi: ";
    l.printF(); cout << endl;

    l.insert(6,2);
    cout << "Duyet xuoi sau khi them 6 vao vi tri 2: ";
    l.printF(); cout << endl;

    l.deleteL();
    cout << "Duyet xuoi sau khi xoa cuoi: ";
    l.printF(); cout << endl;

    

    l.deletE(2);
    cout << "Duyet xuoi sau khi xoa tai vi tri 2: ";
    l.printF(); cout << endl;

    l.deleteF();
    cout << "Duyet xuoi sau khi xoa dau: ";
    l.printF(); cout << endl;

    
    return 0;
   

}