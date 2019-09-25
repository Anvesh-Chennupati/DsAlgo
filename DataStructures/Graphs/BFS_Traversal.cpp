#include<iostream>
#include<vector>
#include<list>

using namespace std;
class Graph{
    unsigned int V;
    list<unsigned int> *edges;
    public:
    Graph(unsigned int V);
    void addEdge(unsigned int u, unsigned int v);
    void BFS(unsigned int s);
};

Graph::Graph(unsigned int V){
    this->V = V;
    edges = new list<unsigned int>[V];
}

void Graph::addEdge(unsigned int u,unsigned int v){
    edges[u].push_back(v);
}

void Graph::BFS(unsigned int s){
    bool *visited = new bool[V];
    for(int i=0; i<V; i++)
        visited[i] = false;
    list<unsigned int> queue;

    queue.push_back(s);
    visited[s] = true;
    list<unsigned int>::iterator i;

    while(!queue.empty()){
        s = queue.front();
        cout<<s <<" ";
        queue.pop_front();

        for(i = edges[s].begin(); i!= edges[s].end(); i++){
            if(!visited[*i]){
                visited[*i] = true;
                queue.push_back(*i);
            }
        }
    }
}

int main(int argc,char** argv){
    Graph g(5);
    g.addEdge(0,1);
    g.addEdge(0, 2); 
    g.addEdge(1, 2); 
    g.addEdge(2, 0); 
    g.addEdge(2, 3); 
    g.addEdge(3, 3);
    cout<<"\nBFS Traversal of graph starting at vertex: 2\n";
    g.BFS(2);
    return 0;
}