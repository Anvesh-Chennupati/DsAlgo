#include<iostream>
#include<vector>
#include<string>
#include<set>

using namespace std;

class PrimeSubTree
{
private:
    int value;

public:
    PrimeSubTree(int val){

    }
};

void printVectors(string name,vector<int> gVector){
    cout<<name<<": ";

    for(int i= 0; i <gVector.size();i++){
        cout<<gVector[i]<<" ";
    }
    cout<<endl;
}

int main(){
    int n,fn,sn,vn,qn;
    set<int> node;
    vector<int> nodes;
    vector<int> first;
    vector<int> second;
    vector<int> values;
    vector<int> queries;
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

    printVectors("Nodes",nodes);
    printVectors("First",first);
    printVectors("Second",second);
    printVectors("Values",values);
    printVectors("Queries",queries);

    return 0;       
}
