#include<iostream>

using namespace std;

class Tree{
    public:
    int data;
    Tree* left,*right;

    Tree(int data){
        this->data = data;
        left = right = NULL;
    }
};

void inOrderTraversal(Tree *root){
    if(root == NULL){
        return;
    }

    inOrderTraversal(root->left);

    cout<<" "<<root->data;

    inOrderTraversal(root->right);
}

void preOrderTraversal(Tree *root){
    if(root == nullptr) return;

    cout<<" "<<root->data;

    preOrderTraversal(root->left);
    preOrderTraversal(root->right);
}
void postOrderTraversal(Tree *root){
    if(root == NULL) return;

    postOrderTraversal(root->left);
    postOrderTraversal(root->right);
    cout<<" "<<root->data;
}
int main(){
    Tree *root = new Tree(4);
    root->left = new Tree(2);
    root->left->left = new Tree(1);
    root->left->right = new Tree(3);
    root->right = new Tree(6);
    root->right->left = new Tree(5);
    root->right->right = new Tree(7);

    cout<<"\nInorder Traversal: ";
    inOrderTraversal(root);
    cout<<"\nPreorder Traversal: ";
    preOrderTraversal(root);
    cout<<"\nPostorder Traversal: ";
    postOrderTraversal(root);
    return 0;
}