#include<iostream>

using namespace std;

class Tree{
    public:
    int data;
    Tree* left, *right;

    Tree(int data){
        this->data = data;
        left = right = nullptr;
    }
};

int sizeTree(Tree* root){
    if(root == NULL){
        return 0;
    }

    int lsize = sizeTree(root->left);
    int rsize = sizeTree(root->right);

    return lsize + rsize +1;
}

int main(){
    Tree *root = new Tree(4);
    root->left = new Tree(2);
    root->left->left = new Tree(1);
    root->left->right = new Tree(3);
    root->right = new Tree(6);
    root->right->left = new Tree(5);
    root->right->right = new Tree(7);

    cout<<"\nSizeo of Binary Tree: "<<sizeTree(root);
}