#include<iostream>
#include<vector>

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

bool rootToLeafSum(Tree* root,int sum,vector<int> &res){
    if(root == NULL){
        return NULL;
    }

    if(root->left == NULL && root->right ==NULL){
        if(root->data == sum){
            // cout<<" "<<root->data;
            res.push_back(root->data);
            return true;
        }
        else{
            return false;
        }
    }

    if(rootToLeafSum(root->left,sum-root->data,res)){
        // cout<<" "<<root->data;
        res.push_back(root->data);
        return true;
    }

    if(rootToLeafSum(root->right,sum - root->data,res)){
        // cout<<" "<<root->data;
        res.push_back(root->data);
        return true;
    }
}

int main(){
    Tree* root = new Tree(10);
    root->left = new Tree(16);
    root->left->right = new Tree(-3);
    root->right = new Tree(5);
    root->right->left = new Tree(6);
    root->right->right = new Tree(11);

    vector<int> res;

    if(rootToLeafSum(root,26,res)){
        cout<<"\n Sum exits in the following path";
        for(auto x:res)
            cout<<" "<<x;
    }
    else{
        cout<<"\n Sum doesn't exists";
    }
    return 0;
}