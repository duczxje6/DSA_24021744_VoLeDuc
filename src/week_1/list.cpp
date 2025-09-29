#include <iostream>
using namespace std;
struct List {
    int size;  
    int a[] ;

    List() {
    size = 0;
}
    
    List(int n, int arr[]) {
        size = n;
        for (int i = 0; i < n; i++) {
            a[i] = arr[i];
        }
    }
    

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
        a[index] = data;        // O[n]
    }

    // Xóa phần tử đầu
    int deleteF (){
        int x = a[0];
        for (int i=size-1; i>0; i--){
            a[i-1] = a[i];      // O[n]
        }
        size--;
        return x; 
    }

    // Xóa phần tử cuối
    int deleteL (){
         int x = a[size-1];
         size--;
         return x;                // O[1]
    }
 
    // Xóa vị trí i
    void deletE (int index){
        for (int i=size-1; i>index; i--){
            a[i-1] = a[i];       // O[n]
        }
        size--;
    }

    // Duyệt xuôi
    void printF (){
        for(int i=0; i<=size-1; i++){
            cout<<a[i]<<" ";         // O[n]
        }
    }

    // Duyệt ngược
    void printB(){
        for(int i=size-1; i>=0; i--){
            cout<<a[i]<<" ";          // O[n]
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
        return list.search(list.size-1);
    }
    void print(){
       list.printF();
    }

};
struct Queue {
    List list;
    void enqueue (int item){
        list.insertL(item);
    }
    int dequeue (){
        return list.deleteF();
    }
     void print(){
        list.printF();
    }

};
int main() { 
    // List
    
    List l;
    l.insertF(7);
    l.insertF(0);
    l.insertF(5);
    l.insertF(3);
    l.insertF(1);
    cout << "Duyet xuoi: "; l.printF(); cout<<endl;
    cout << "Duyet nguoc: "; l.printB(); cout<<endl;

    l.insertL(9);
    cout << "Sau khi them 9 cuoi: "; l.printF(); cout<<endl;

    l.insert(6,2);
    cout << "Sau khi them 6 vao vi tri 2: "; l.printF(); cout<<endl;

    l.deleteL();
    cout << "Sau khi xoa cuoi: "; l.printF(); cout<<endl;

    l.deletE(2);
    cout << "Sau khi xoa tai vi tri 2: "; l.printF(); cout<<endl; 

    l.deleteF();
    cout << "Sau khi xoa dau: "; l.printF(); cout<<endl;


    // Stack
    Stack st;
    st.Push(10);
    st.Push(20);
    st.Push(30);
    cout << "Stack sau khi push 10, 20, 30: "; st.print(); cout<<endl;
    cout << "Top = " << st.top() << endl; cout<<endl;
    cout << "Pop = " << st.pop() << endl; cout<<endl;
    cout << "Stack sau khi pop: "; st.print(); cout<<endl;


    // Queue
    Queue q;
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    cout << "Queue sau khi enqueue 1, 2, 3: "; q.print(); cout<<endl;
    cout << "Dequeue = " << q.dequeue() << endl; cout<<endl;
    cout << "Queue sau khi dequeue: "; q.print(); cout<<endl; 

    return 0;
}