//check if two trees are same

#include<iostream>

using namespace std;

class Tree{
    public:
    int data;
    Tree *left,*right;

    Tree(int val){
        this->data = val;
        left = right = NULL;
    }
};

bool sameTree(Tree* r1, Tree*r2){
    if(r1==NULL && r2 == NULL){
        // cout<<"\n Trees are same";
        return true;;
    }

    if((r1 ==NULL && r2!=NULL) || (r1!= NULL && r2==NULL)){
        // cout<<"\n Trees are not same";
        return false;
    }

    if(r1->data != r2->data){
        // cout<<"\n Trees are not same";
        return false;
    }
    else{
        sameTree(r1->left,r2->left);
        sameTree(r1->right,r2->right);
    }
}

int main(){
    Tree *r1 = new Tree(4);
    r1->left = new Tree(2);
    r1->left->left = new Tree(1);
    r1->left->right = new Tree(3);
    r1->right = new Tree(6);
    r1->right->left = new Tree(5);
    r1->right->right = new Tree(7);


    Tree *r2 = new Tree(4);
    r2->left = new Tree(2);
    r2->left->left = new Tree(1);
    r2->left->right = new Tree(3);
    r2->right = new Tree(6);
    r2->right->left = new Tree(5);
    r2->right->right = new Tree(7);

    if(sameTree(r1,r2))
        cout<<"\n Similar tree";
    else 
        cout<<"\n Not similar";

}