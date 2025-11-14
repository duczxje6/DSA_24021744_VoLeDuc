#include <iostream>
using namespace std;
struct Node {
    int data ;
    Node* next;
};
class LinkedList {
private:
    Node* head; 
    Node* tail;
    void printBackward(Node *q){
        if(q == NULL){
            return;
        }
        printBackward(q->next);
        cout<<q->data<< " ";
    }
public: 
    LinkedList() {
        head = NULL;
        tail = NULL;
    }
    // Truy cập
    int search (int index){                   //O[n]
        Node *current = head;
        for (int i=0; i<index; i++){
            current = current ->next;   
    }
    return  current->data ;  
    }   
    int searchLast (){                        //O[n]
        return tail->data;
    }

    // Chèn phần tử vào đầu
    void insertF (int data){                   //O[1]
        Node *q;
        q = new Node;
        q ->data = data ;
        q ->next = head;
        head = q;
        if (tail = NULL) tail = q;
    }

    // Chèn phần tử vào cuối                    
    void insertL (int data){                   //O[n]
        Node *q;
        q = new Node;
        q ->data = data;
        q ->next = NULL; 
        tail->next = q;
        tail = q;
    }

    // Chèn vào vị trí i 
    void insert (int data, int index){          //O[n]
        Node *q;
        Node *current = head;
        q = new Node;
        q ->data = data;
        for (int i=1; i<index-1; i++){
            current = current ->next;
        }
        q->next = current->next;
        current->next = q;
        if (q->next = NULL) tail = q;
    }   

    // Xóa phần tử đầu
    int deleteF (){                              //O[1]
        Node *current = head;
        head = head->next;
        int x = current->data;
        delete current;
        return x;
    }

    // Xóa phần tử cuối
    int deleteL (){                               //O[n]
        Node *current = head;
        while (current->next !=NULL){
            current = current->next;
        }
        int x = current->data;
        delete current;
        return x;
        
    }

    // Xóa vị trí i                               //O[n]
    void deletE (int index){
        Node *current = head;
        Node *q;
        q = new Node; 
        for (int i=1; i<index-1 ; i++){
            current = current ->next;
        }
        q = current->next;
        current->next = q->next;
        delete q;
    }

    // Duyệt xuôi
    void printF(){                                //O[n]
        Node *current = head;
        while(current != NULL){
            cout<< current->data<<" ";
            current = current->next;
        }
    }

    // Duyệt ngược
    void printB(){                                //O[n]
        printBackward(head);
    }
     bool empty(){
        return head == NULL;
    }
    
};
struct Stack{
    LinkedList llist;
    void Push(int item){
        llist.insertL(item);
    }
    int pop(){
       return llist.deleteL(); // xóa cuối trả về phần tử cuối   
    }
    int top(){
        return llist.searchLast();
    }
    void print(){
       llist.printF();
    }
    bool empty(){
        return llist.empty();
    }


};
struct Queue{
    LinkedList llist;
    void enqueue (int item){
        llist.insertL(item);
    }
    int dequeue (){
        return llist.deleteF();
    }
     void print(){
        llist.printF();
    }
    bool empty(){
        return llist.empty();
    }

};

int main()
{
    // LinkedList demo
   
    LinkedList list;
    list.insertF(7);
    list.insertF(3);
    list.insertL(1);
    list.insert(5, 2);
    cout << "Danh sach: "; list.printF();
    cout << "Duyet nguoc: "; list.printB();

    cout << "Phan tu tai index 2: " << list.search(2) << endl;

    list.deleteF();
    cout << "Sau khi xoa dau: "; list.printF();

    list.deleteL();
    cout << "Sau khi xoa cuoi: "; list.printF();

    list.deletE(1);
    cout << "Sau khi xoa index 1: "; list.printF();

    // Stack demo
    
    Stack st;
    st.Push(10);
    st.Push(20);
    st.Push(30);
    cout << "Stack sau khi push 10,20,30: "; st.print();
    cout << "Top = " << st.top() << endl;
    cout << "Pop = " << st.pop() << endl;
    cout << "Stack sau khi pop: "; st.print();

    // Queue demo
    
    Queue q;
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    cout << "Queue sau khi enqueue 1,2,3: "; q.print();
    cout << "Dequeue = " << q.dequeue() << endl;
    cout << "Queue sau khi dequeue: "; q.print();

    return 0;
}
 
    