#include<iostream>
#include<vector>
#include<string>
#include<queue>
#include<set>
#include<stdlib.h>
#include<unordered_map>

using namespace std;

struct PrimeSubTree 
{ 
	int val; 
	vector<PrimeSubTree *>child; 
}; 

PrimeSubTree *newNode(int val) 
{ 
	PrimeSubTree *temp = new PrimeSubTree; 
	temp->val = val; 
	return temp; 
} 

void printVectors(string name,vector<int> gVector){
    cout<<name<<": ";

    for(int i= 0; i <gVector.size();i++){
        cout<<gVector[i]<<" ";
    }
    cout<<endl;
}

void levelOrderTree(PrimeSubTree* root){

    if(root == NULL){
        cout<<"\nEmpty Tree";
    }

    queue<PrimeSubTree*> q;
    q.push(root);
    while (!q.empty()) 
    { 
        int n = q.size(); 

        while (n > 0) 
        { 
            PrimeSubTree * p = q.front(); 
            q.pop(); 
            cout << p->val << " "; 
   
            for (int i=0; i<p->child.size(); i++) 
                q.push(p->child[i]); 
            n--; 
        } 
   
        cout << endl;
    } 

}

PrimeSubTree* CreateTree(vector<int> nodes,vector<int> first, vector<int> second, vector<int> values){

    PrimeSubTree* root = NULL;
    unordered_map<int,int> nodeVal;
    if(nodes.size()!= first.size()!=second.size()!=values.size()){
        cout<<"\n Invalid parameters";
        exit(0);
    }
    else{
        //populating map
    }

    return root;    
}
vector<int> primeQuery(int n, vector<int> first, vector<int> second, vector<int> values, vector<int> queries) {
  vector<int> ans;
  set<int> node;
  vector<int> nodes;
    for(int i=0; i<first.size() || i <second.size();i++){
        node.insert(first[i]);
        node.insert(second[i]);
    }

    set<int>::iterator it =node.begin();
 
    while (it != node.end())
    {
        nodes.push_back(*it);
	    it++;
    }
  PrimeSubTree* root = CreateTree(nodes,first,second,values);

  return ans;
}

int main(){
    int n,fn,sn,vn,qn;
    set<int> node;
    vector<int> nodes;
    vector<int> first;
    vector<int> second;
    vector<int> values;
    vector<int> queries;
    vector<int> ans;
    cin>>n;

    int temp;
    cin>>fn;
    for(int i=0;i < fn;i++){
        cin>>temp;
        first.push_back(temp);
        temp= 0;
    }
    cin>>sn;
    for(int i=0;i < sn;i++){
        cin>>temp;
        second.push_back(temp);
        temp= 0;
    }
    cin>>vn;
    for(int i=0;i < vn;i++){
        cin>>temp;
        values.push_back(temp);
        temp= 0;
    }

    cin>>qn;
    for(int i=0;i < qn;i++){
        cin>>temp;
        queries.push_back(temp);
        temp= 0;
    }

    printVectors("First",first);
    printVectors("Second",second);
    printVectors("Values",values);
    printVectors("Queries",queries);
    ans = primeQuery(n,first,second,values,queries);
    printVectors("Answers", ans);
    
    // PrimeSubTree *root = newNode(17); 
	// (root->child).push_back(newNode(29)); 
	// (root->child).push_back(newNode(23)); 
	// (root->child[1]->child).push_back(newNode(20)); 
    // (root->child[1]->child).push_back(newNode(11)); 
    // (root->child[1]->child).push_back(newNode(5)); 
    // (root->child[1]->child).push_back(newNode(15));
    // (root->child[1]->child[1]->child).push_back(newNode(3));  
    // (root->child[1]->child[2]->child).push_back(newNode(8));
    // (root->child[1]->child[2]->child[0]->child).push_back(newNode(3));

    // levelOrderTree(root);

}
