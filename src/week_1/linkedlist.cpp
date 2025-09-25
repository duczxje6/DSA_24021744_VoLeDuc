#include <iostream>
using namespace std;
struct Node {
    int data ;
    Node* next;
};
class LinkedList {
private:
    Node* head; 
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
    }
    // Truy cập
    int search (int index){
        Node *current = head;
        for (int i=0; i<index; i++){
            current = current ->next;
    }
    return  current->data ;
    }   

    // Chèn phần tử vào đầu
    void insertF (int data){
        Node *q;
        q = new Node;
        q ->data = data ;
        q ->next = head;
        head = q;
    }

    // Chèn phần tử vào cuối
    void insertL (int data){
        Node *q;
        Node *current = head;
        q = new Node;
        q ->data = data;
        q ->next = NULL; 
        while (current->next != NULL){
            current = current ->next;
        }
        current->next = q;     
    }

    // Chèn vào vị trí i 
    void insert (int data, int index){
        Node *q;
        Node *current = head;
        q = new Node;
        q ->data = data;
        for (int i=1; i<index-1; i++){
            current = current ->next;
        }
        q->next = current->next;
        current->next = q;
    }   

    // Xóa phần tử đầu
    void deleteF (){
        Node *current = head;
        head = head->next;
        delete current;
    }

    // Xóa phần tử cuối
    void deleteL (){
        Node *current = head;
        while (current->next !=NULL){
            current = current->next;
        }
        delete current;
        
    }

    // Xóa vị trí i
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
    void printF(){
        Node *current = head;
        while(current != NULL){
            cout<< current->data<<" ";
            current = current->next;
        }
    }

    // Duyệt ngược
    void printB(){
        printBackward(head);
    }

};
int main()
{
    LinkedList list;

    // Thêm phần tử
    list.insertF(7);   
    list.insertF(3);   
    list.insertL(1);   
    list.insert(5, 2); 

    cout << "Danh sach hien tai: ";
    list.printF(); cout <<endl;
     

   cout << "Duyet nguoc: ";
    list.printB(); 

    cout << "Phan tu tai index 2: " << list.search(2) << endl; 

    list.deleteF(); 
    cout << "Sau khi xoa dau: ";
    list.printF(); cout <<endl;

    list.deleteL(); 
    cout << "Sau khi xoa cuoi: ";
    list.printF(); cout <<endl;

    list.deletE(1); 
    cout << "Sau khi xoa index 1: ";
    list.printF(); cout <<endl;

    return 0;
}

 
    