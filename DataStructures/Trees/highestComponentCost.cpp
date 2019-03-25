#include<iostream>
#include<vector>
#include<queue>

using namespace std;

class TreeNode{
    public:
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int value){
        this->val = value;
        left = right = nullptr;
    }
};

void levelOrderTraversal(TreeNode* root, vector<vector<int> >& ans){
    if(root == NULL){
        cout<<"\nTree is empty";
    }

    else{
        queue<TreeNode*> s;
        vector<int> tempVector;

        s.push(root);
        s.push(NULL);

        while(s.empty()==false){
            TreeNode* temp = s.front();
            s.pop();

            if(temp==NULL){
                ans.push_back(tempVector);
                tempVector.resize(0);

                if(s.size() > 0) s.push(NULL);
            }
            else{
                tempVector.push_back(temp->val);
                if(temp->left) s.push(temp->left);
                if(temp->right) s.push(temp->right);
            }

        }
    }

}

int main(){
    TreeNode *root = new TreeNode(200);
    root->left = new TreeNode(120);
    root->right = new TreeNode(180);
    root->left->left = new TreeNode(110);
    root->left->right = new TreeNode(12);

    vector<vector<int> > ans;
    levelOrderTraversal(root,ans);
    for(auto x:ans){
        cout<<"\n";
        for(auto y:x){
            cout<<y<<" ";
        }
    }
    return 0;
}