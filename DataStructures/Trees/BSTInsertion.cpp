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

void insert(Tree* &root,int data){
    if(root == NULL){
        root = new Tree(data);
        return;
    }

    Tree* parent = NULL;
    Tree* curr = root;

    while(curr!= NULL){
        parent = curr;

        if(curr->data <data)
            curr = curr->right;
        
        else curr = curr->left;
    }

    if(parent->data <data){
        parent->right =new Tree(data);
    }
    else {
        parent->left = new Tree(data);
    }


}

void inOrder(Tree* &root){
    if(root==NULL){
        // cout<<"\n Tree empty";
        return;
    }

    inOrder(root->left);
    cout<<" "<<root->data;
    inOrder(root->right);
}

int main(){
    Tree* root = NULL;
    for(int i = 0;i <12;i++){
        insert(root,i);
    }

     inOrder(root);

    // cout<<root->data;
    // cout<<root->right->right->data;
    // return 0;
}