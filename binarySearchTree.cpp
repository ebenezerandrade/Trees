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

//consult value in tree.
int consultValue(NODE *auxiliar, int value, int find){
  if(auxiliar != NULL && find == 0){
    if(auxiliar->value == value){
      find = 1;
    } else if (value < auxiliar->value){
      find = consultValue(auxiliar->left, value, find);
    } else if (value > auxiliar->value){
      find = consultValue(auxiliar->right, value, find);
    }
  }
  return find;
}

int main(){

    NODE *root = NULL;
    NODE *auxiliar;
    int operation, value, find;

    do {
      cout << "\n Options for operation" << '\n';
      cout << "\n 1 - Insert value in tree" << '\n';
      cout << "\n 2 - Select all tree in order" << '\n';
      cout << "\n 3 - Consult value in tree" << '\n';

      cin >> operation;
      if (operation < 1 || operation > 4) {
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
      } else if (operation == 3) {
          if(root == NULL){
            cout << "The Tree is null!" << '\n';
          } else {
            cout << "Insert the value of consult: ";
            cin >> value;
            find = 0;
            find = consultValue(root, value, find);
            if (find == 0){
                cout << "Value not exist in Tree" << '\n';
            } else{
              cout << "Value found" << '\n';
            }
          }
      }
    } while(operation!=4);
    return 0;
}
