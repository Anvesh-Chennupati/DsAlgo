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

bool helper(Tree* l, Tree* r){
    if(l == NULL && r== NULL){
        return true;
    }

    if(l == NULL || r ==NULL){
        return false;
    }

    if(l->data != r->data){
        return false;
    }

    return (helper(l->left,r->right) && helper(l->right, r->left));
}

bool SymmetricTree(Tree* node){
    if(!node)
        return true;
    
    return helper(node->left,node->right);
}

int main(){
    Tree *root = new Tree(1);
    root->left = new Tree(2);
    root->right = new Tree(2);
    // root->left = new Tree(2);
    // root->left->left = new Tree(3);
    // root->left->right = new Tree(4);
    // root->right = new Tree(2);
    // root->right->left = new Tree(4);
    // root->right->right = new Tree(3);
    if(SymmetricTree(root)){
        cout<<"\nSymmetric Tree";
    }
    else{
         cout<<"\nAsymmetric Tree";
    }
    return 0;
}