#include <iostream>
using namespace std;

template <class Item>
struct Node
{
Item data; // Dữ liệu chứa trong mỗi đỉnh
Node* left;
Node* right;
};

template <class Item>
void Preorder (Node <Item> * root, void f (Item &)){
// Thăm các đỉnh của cây nhị phân theo thứ tự trước
if (root!= NULL){
    f (root ->data)
    Preorder (root ->left, f);
    Preorder (root ->right, f); 
  }  
}
template <class Item>
void Inorder(Node <Item> * root, void f (Item &)){
if (root!= NULL){
  Inorder (left ->root, f);
  f (root ->data);
  Inorder (right ->root, f);
  }
}

template <class Item>
void Postorder(Node <Item> * root, void f (Item &)){
if (root!= NULL){
  Postorder (left ->root, f);
  Postorder (right ->root, f);
  f (root-> data);
  }
}