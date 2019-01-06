#include<iostream>
#include<vector>

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

void Inorder(Tree* node){
    if(node == NULL)
        return;
    
    Inorder(node->left);

    cout<<' '<<node->data;

    Inorder(node->right);
}

Tree* helper(vector<int>& nums, int start, int end){
    if(end<=start) return NULL; 
    int mid = (end + start)/2;
    Tree* root = new Tree(nums[mid]);
    root->left = helper(nums,start,mid);
    root->right = helper(nums,mid+1,end);

    return root;
}

void createTree(vector<int> nums){
    Inorder(helper(nums,0,nums.size()));
}

int main(){
    vector<int> nums = {1,2,3,4,5,6,7};
    createTree(nums);
}