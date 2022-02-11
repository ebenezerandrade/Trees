#include<iostream>

using namespace std;

//defined node for represent of elements in tree
struct NODE{
  int value;
  NODE *left, *right;
};

//insert a new node into tree
NODE* insertNode(NODE* auxiliar, int value){
  if(auxiliar == NULL){
    auxiliar = new NODE();
    auxiliar->value = value;
    auxiliar->left = NULL;
    auxiliar->right = NULL;
  }else if (value < auxiliar->value){
    auxiliar->left = insertNode(auxiliar->left, value);
  } else if (value > auxiliar->value){
    auxiliar->right = insertNode(auxiliar->right, value);
  }
  return auxiliar;
}

//show nodes in growing order
void showInOrder(NODE *auxiliar){
  if (auxiliar != NULL) {
    showInOrder(auxiliar->left);
    cout << auxiliar->value << " ";
    showInOrder(auxiliar->right);
  }
}

int main(){

    NODE *root = NULL;
    NODE *auxiliar;
    int operation, value;

    do {
      cout << "\n Options for operation" << '\n';
      cout << "\n 1 - Insert value in tree" << '\n';
      cout << "\n 2 - Select all tree in order" << '\n';

      cin >> operation;
      if (operation < 1 || operation > 2) {
        cout << "Invalid option!" << '\n';
      } else if (operation == 1) {
        cout << "Insert a value: ";
        cin >> value;
        root = insertNode(root, value);
        cout << "Value inserted with sucess!";
      } else if (operation == 2) {
        if (root == NULL) {
          cout << "Tree is null";
        } else {
          cout << "elements in order in tree: " << '\n';
          showInOrder(root);
        }
      }
    } while(operation!=3);
    return 0;
}
