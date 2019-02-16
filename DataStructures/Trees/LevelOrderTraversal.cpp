#include<iostream>
#include<vector>
#include<stack>
#include<queue>
using namespace std;

class TreeNode
{
public:
    int val;
    TreeNode* left,*right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
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
    TreeNode* root = new TreeNode(10);
    root->left = new TreeNode(16);
    root->left->right = new TreeNode(-3);
    root->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(11);
    vector<vector<int> > ans;
    levelOrderTraversal(root,ans);
    for(auto x:ans){
        cout<<"\n";
        for(auto y:x){
            cout<<y<<" ";
        }
    }
}
