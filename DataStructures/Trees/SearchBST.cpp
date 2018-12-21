#include<iostream>

using namespace std;

class Tree{
    public:
    int data;
    Tree *left,*right;

    Tree(int data){
        this->data = data;
        left = right = NULL;
    }
};

void searchBST(Tree *root,int val){
    if(root == NULL){
        cout<<"\nValue not present in Tree";
        return;
    }

    if(root->data == val){
        cout<<"\nValue present in Tree";
        return;
    }

    if(root->data > val){
        searchBST(root->left,val);
    }
    else{
        searchBST(root->right,val);
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

    searchBST(root,13);
}