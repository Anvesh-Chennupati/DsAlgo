#include<iostream>
#include<bits/stdc++.h>

using namespace std;

struct Tree{
    int data;
    struct Tree* left;
    struct Tree* right;

};

struct Tree* newnode(int data){
    struct Tree* temp = new Tree;
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
};

void inOrderR(struct Tree* root){
    if(!root)
        return;
    inOrderR(root->left);
    cout<<" "<<root->data;
    inOrderR(root->right);
}

void inOrderI(struct Tree* root){
    stack <struct Tree*> s;
    struct Tree* curr = root;

    while(curr!=NULL || s.empty()==false){
        while(curr!=NULL){
            s.push(curr);
            curr= curr->left;
        }

        curr = s.top();
        s.pop();

        cout<<" "<<curr->data;

        curr = curr->right;
    }

}

int main(int argc, char* argv[]){
    struct Tree* root = newnode(5);
    root->left = newnode(1);
    root->right = newnode(4);
    root->right->left = newnode(3);
    root->right->right = newnode(6);
    inOrderR(root);
    cout<<"\n";
    inOrderI(root);
}