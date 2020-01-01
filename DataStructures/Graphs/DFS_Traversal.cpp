#include<iostream>
#include<list>

using namespace std;

class Graph{
    int V;
    int E;
    void DFSUtil(int v, bool visited[]);
    list<int> *adj;

    public:
    Graph(int numVertex);
    void addEdge(int u, int v);
    void DFS(int vertex);
    void numEdges();
};

Graph::Graph(int numVertex){
    this->V = numVertex;
    adj = new list<int>[V];
    this->E = 0;
}

void Graph::addEdge(int u, int v){
    adj[u].push_back(v);
    E++;
}

void Graph::DFS(int vertex){
    cout<<"\nStarting DFS traversal from vertex: "<<vertex<< endl;
    bool* visited = new bool[V];
    for(int i =0; i< V; i++){
        visited[i] = false;
    }
    DFSUtil(vertex, visited);
}


void Graph::DFSUtil(int v, bool *visited){
    visited[v] = true; 
    cout << v << " "; 
    list<int>::iterator it;
    for(it= adj[v].begin(); it!=adj[v].end(); it++){
        if(!visited[*it]){
            DFSUtil(*it,visited);
        }
    }
}

void Graph::numEdges(){
    cout<<"\nNumber of Edges: "<<this->E<<endl;
}

int main(int argv, char* argc[]){
    Graph g(11);
    g.addEdge(1,2);
    g.addEdge(1,3);
    g.addEdge(1,4);
    g.addEdge(1,5);
    g.addEdge(2,6);
    g.addEdge(3,7);
    g.addEdge(4,8);
    g.addEdge(5,9);
    g.addEdge(6,10);
    g.addEdge(7,10);
    g.addEdge(8,10);
    g.addEdge(9,10);
    g.numEdges();
    g.DFS(1);
    return 0;
}