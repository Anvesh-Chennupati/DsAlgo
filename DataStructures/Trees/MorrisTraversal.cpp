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

void MorrisinOrderTraversal(Tree* node){
    Tree* curr = node;

    while(curr!= NULL){
        if(curr->left == NULL){
            cout<<" "<<curr->data;
            curr = curr->right;
        }
        else{
            Tree* pre = curr->left;

            while(pre->right!= curr && pre->right!= NULL){
                pre = pre->right;
            }

            if(pre->right==NULL){
                pre->right = curr;
                curr = curr->left;
            }
            else{
                pre->right = NULL;
                cout<< " "<<curr->data;
                curr = curr->right;
            }
        }

    }
}

void MorrispreOrderTraversal(Tree* node){
    
    Tree* curr = node;

    while(curr!= NULL){
        if(curr->left == NULL){
            cout<<" "<<curr->data;
            curr = curr->right;
        }
        else{
            Tree* pre = curr->left;

            while(pre->right!= curr && pre->right!= NULL){
                pre = pre->right;
            }

            if(pre->right==NULL){
                 cout<< " "<<curr->data;
                pre->right = curr;
                curr = curr->left;
            }
            else{
                pre->right = NULL;
                curr = curr->right;
            }
        }

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

    cout<<"\nMorris Inorder Traversal: ";
    MorrisinOrderTraversal(root);
    cout<<"\nMorris Preorder Traversal: ";
    MorrispreOrderTraversal(root);
    return 0;
}

