#include<iostream>
#include<bits/stdc++.h>

using namespace std;

struct Tree{
    int data;
    struct Tree* left;
    struct Tree* right;
};

struct Tree* newnode(int data){
    struct Tree* newnode = (struct Tree *)malloc(sizeof(struct Tree));
    newnode->data = data;
    newnode->left = NULL;
    newnode->right = NULL;
    return newnode;
}

int main(){
    struct Tree* root = newnode(1);
    root->left = newnode(2);
    root->right = newnode(3);
    root->left->left = newnode(4);
    root->left->right = newnode(5);
    root->right->left = newnode(6);
    root->right->right = newnode(7);
}