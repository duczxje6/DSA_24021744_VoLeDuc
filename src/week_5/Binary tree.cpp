#include <iostream>
using namespace std;

template <class Item>
struct Node
{
Item data; // Dữ liệu chứa trong mỗi đỉnh
Node* root;
Node* left;
Node* right;
};

template <class Item>
void Preorder (Node <Item> * root, void f (Item &)){
// Thăm các đỉnh của cây nhị phân theo thứ tự trước
if (root! = NULL){
    f (root ->data);
    Preorder (root ->left, f);
    Preorder (root ->right, f);
  }  
}
template <class Item>
void Inorder(Node <Item> * root, void f (Item &)){

}

template <class Item>
void Postorder(Node <Item> * root, void f (Item &)){

}