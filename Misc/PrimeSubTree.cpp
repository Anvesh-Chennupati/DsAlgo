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

bool isPrime(int n){
    if (n <= 1)  return false; 
  
    // Check from 2 to n-1 
    for (int i=2; i<n; i++) 
        if (n%i == 0) 
            return false; 

    return true; 
}

int countPrimes(PrimeSubTree* node){
    int cnt =0;
    if(node == NULL){
        return 0;
    }
    queue<PrimeSubTree*> q;
    q.push(node);
    while (!q.empty()) 
    { 
        int n = q.size(); 

        while (n > 0) 
        { 
            PrimeSubTree * p = q.front(); 
            q.pop();
            if(isPrime(p->val)) cnt++; 
   
            for (int i=0; i<p->child.size(); i++) 
                q.push(p->child[i]); 
            n--; 
        }
    }
    return cnt; 

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

PrimeSubTree* findNode(PrimeSubTree* root, int val){
    if(root == NULL){
        cout<<"\nEmpty Tree";
        exit(0);
    }
    else{
        if(root->val == val){
            return root;
        }
        else{
            queue<PrimeSubTree*> q;
            q.push(root);
            while(!q.empty()){
                int n = q.size();
                while(n > 0){
                    PrimeSubTree * p = q.front();
                    q.pop();
                    if(p->val == val){
                        return p;
                    }
                    else{
                        for (int i=0; i<p->child.size(); i++)
                            q.push(p->child[i]);
                    }
                    n--;

                }
            }
        }

    }
}

PrimeSubTree* CreateTree(unordered_map<int,int> nodeVal,vector<int> nodes,vector<int> first, vector<int> second, vector<int> values){

    PrimeSubTree* root = NULL;
    // unordered_map<int,int> nodeVal;
    if((first.size()!=second.size()) || (nodes.size()!=values.size())){
        cout<<"\n"<<nodes.size();
        cout<<"\n Invalid parameters";
        exit(0);
    }
    else{
        //populating map
        // for(int i=0;i <nodes.size();i++){
        //     // cout<<"\n node:value "<<nodes[i]<<" : "<<values[i];
        //     nodeVal.insert({nodes[i],values[i]});
        // }
        // for(auto x:nodeVal){
        //     // cout<<"\nfirst "<<x.first<<" second "<<x.second;
        // }
        queue<int> check;
        check.push(nodes[0]);
        while(!check.empty()){
            if(root == NULL){
                int numb = check.front();
                check.pop();
                root = newNode(nodeVal.at(numb));
                for(int j=0; j<first.size(); j++){
                    if(first[j] == numb){
                        root->child.push_back(newNode(nodeVal.at(second[j])));
                        check.push(second[j]);
                        first.erase(first.begin()+j);
                        // for(auto x: first)
                        //     cout<<" "<< x;

                        // cout<<"\n";                            
                        second.erase(second.begin()+j);
                        // for(auto x: second)
                        //     cout<<" "<< x;

                        // cout<<"\n";
                        j=0;                                                 
                    }
                    if(second[j] == numb){
                        root->child.push_back(newNode(nodeVal.at(first[j])));
                        check.push(first[j]);
                        first.erase(first.begin()+j);
                        // for(auto x: first)
                        //     cout<<" "<< x;

                        // cout<<"\n";                         
                        second.erase(second.begin()+j);
                        // for(auto x: second)
                        //     cout<<" "<< x;

                        // cout<<"\n";
                        j=0;                         
                    }                                        
                }
            }
            else{
                int numb = check.front();
                check.pop();
                PrimeSubTree* temp = findNode(root, nodeVal.at(numb));
                for(int j=0; j<first.size(); j++){
                    if(first[j] == numb){
                        temp->child.push_back(newNode(nodeVal.at(second[j])));
                        check.push(second[j]);
                        first.erase(first.begin()+j);
                        // for(auto x: first)
                        //     cout<<" "<< x;
                        // cout<<endl;                        
                        second.erase(second.begin()+j); 
                        // for(auto x: second)
                        //     cout<<" "<< x;   
                        // cout<<endl;  
                        j=0;                                          
                    }
                    if(second[j] == numb){
                        temp->child.push_back(newNode(nodeVal.at(first[j])));
                        check.push(first[j]);
                        first.erase(first.begin()+j);
                        // for(auto x: first)
                        //     cout<<" "<< x;

                        // cout<<endl;                                                                                  
                        second.erase(second.begin()+j);
                        // for(auto x: second)
                        //     cout<<" "<< x;    
                        // cout<<endl;
                        j=0;                                           
                    }                    
                }
            }
        }



        // for(int i =0; i< nodes.size();i++){
        //     if(root == NULL){
        //         // cout<<nodeVal.at(nodes[i])<<" here \n";
        //         root = newNode(nodeVal.at(nodes[i]));
        //         for(int j=0; j<first.size(); j++){
        //             if(first[j] == nodes[i]){
        //                 root->child.push_back(newNode(nodeVal.at(second[j])));
        //             }
        //         }
        //     }
        //     else{
        //         PrimeSubTree* temp = findNode()
        //     }
        // }
    }

    return root;    
}
vector<int> primeQuery(int n, vector<int> first, vector<int> second, vector<int> values, vector<int> queries) {
  vector<int> ans;
  set<int> node;
  vector<int> nodes;
  unordered_map<int,int> nodeVal;
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
    for(int i=0;i <nodes.size();i++){
        // cout<<"\n node:value "<<nodes[i]<<" : "<<values[i];
        nodeVal.insert({nodes[i],values[i]});
        }
    PrimeSubTree* root = CreateTree(nodeVal,nodes,first,second,values);
    levelOrderTree(root);

  for(int i =0; i< queries.size(); i++){
      ans.push_back(0);
  }

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
