#include<iostream>
#include<queue>

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

void levelOrder(Tree* root){
    if(root == nullptr){
        cout<<"\n Empty tree";
        return;
    }

    queue<Tree*> q1;

    q1.push(root);
    Tree* temp = NULL;
    cout<<"\n";
    while(!q1.empty()){
        temp = q1.front();
        cout<<" "<<temp->data;
        q1.pop();

        q1.push(temp->left);
        q1.push(temp->right);
    }
    
}

int main(){
    Tree *root = new Tree(1);
    root->left = new Tree(2);
    root->left->left = new Tree(3);
    root->left->right = new Tree(4);
    root->right = new Tree(2);
    root->right->left = new Tree(4);
    root->right->right = new Tree(3);

    levelOrder(root);
    return 0;
}