#include<iostream>
#include<stdlib.h>
using namespace std;

struct Tree{
    int data;
    struct Tree* left, *right;
}root;

struct Tree* Tree(int data){
    struct Tree* new_node = (struct Tree*) malloc(sizeof(struct Tree));
    new_node->data = data;
    new_node->left = nullptr;
    new_node->right = nullptr;

    return new_node;
}

int printHeight(struct Tree* root){
    if(root == NULL){
        return 0;
    }

    int lheight = printHeight(root->left);
    int rheight = printHeight(root->right);

    if(lheight > rheight)
        return (lheight + 1);
    else return (rheight+ 1);
}

void printTree(struct Tree* root){

    if (root == NULL)
        return;
    
    printTree(root->left);

    cout<<" "<<root->data;

    printTree(root->right);
}

int main(){
    struct Tree* root = Tree(1);
    root->left = Tree(2);
    root->right = Tree(3);
    root->left->left = Tree(4);
    root->left->right = Tree(5);
    root->right->left = Tree(6);
    root->right->right = Tree(7);
    root->right->right->right = Tree(8);
    root->right->right->right->right = Tree(9);

    printTree(root);
    cout<<"\nInorder Traversal of Tree: ";
    int height = printHeight(root);
    cout<<"\nHeight of Tree:" <<height;
}