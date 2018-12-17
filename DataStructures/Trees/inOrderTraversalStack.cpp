#include<iostream>
#include<stack>
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

void inOrderTraversal(Tree* root){
    Tree* curr = root;

    stack<Tree* > s;

    while( curr!= NULL || s.empty()==false){

        while(curr != NULL){
            s.push(curr);
            curr = curr->left;
        }

        curr = s.top();
        cout<<" "<<curr->data;

        s.pop();
        curr = curr->right;
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

    cout<<"\nInorder Traversal: ";
    inOrderTraversal(root);
    return 0;
}