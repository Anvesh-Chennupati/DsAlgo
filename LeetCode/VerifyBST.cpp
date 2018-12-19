#include<iostream>

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

bool verifyBST(Tree * root){
    if(root ==NULL){
        return true;
    }
    
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