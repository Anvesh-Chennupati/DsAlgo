#include<iostream>
#include<limits.h>
using namespace std;

class Tree{
    public:
    int data;
    Tree* left, *right;

    Tree(int data){
        this->data = data;
        left = right = NULL;
    }
};

bool validHelper(Tree* root,int min,int max){
    if(root ==NULL){
        return true;
    }

    if(root->data<= min || root->data >max){
        return false;
    }

    return validHelper(root->left,min,root->data) && validHelper(root->right,root->data,max);
}

bool verifyBST(Tree * root){
    if(validHelper(root,INT_MIN,INT_MAX)){
        return true;
    }
    else return false;
}
int main(){
    Tree *root = new Tree(4);
    root->left = new Tree(2);
    root->left->left = new Tree(1);
    root->left->right = new Tree(3);
    root->right = new Tree(6);
    root->right->left = new Tree(5);
    root->right->right = new Tree(7);
    if(verifyBST(root)){
        cout<<"\nValid BST";
    }
    else{
         cout<<"\nInvalid BST";
    }
    return 0;
}