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

bool helper(Tree* node, Tree* minNode,Tree* maxNode){
    if(!node) return true;

    if(minNode && node->data <= minNode->data || maxNode && node->data >= maxNode->data)
        return false;
    
    return helper(node->left,minNode,node) && helper(node->right,node,maxNode);
}

bool verifyBST(Tree* root){
    return helper(root,nullptr,nullptr);
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