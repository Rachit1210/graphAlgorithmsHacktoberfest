#include <iostream>
#include <vector>

using namespace std;

// Graph's Edge class definition
class Edge {
    public:
        int src;
        int dest;
        int wt;

        Edge(int src , int dest , int wt) {
            this->src = src;
            this->dest = dest;
            this->wt = wt;
        }
};

void dfsHelper(vector <vector <Edge> > &graph , vector <bool> &visited , vector <int> &verticesVisited , int source) {
    visited[source] = true;
    verticesVisited.push_back(source);

    for(int i = 0; i < graph[source].size(); i++) {
        Edge adjacentEdge = graph[source][i];
        if(visited[adjacentEdge.dest] == false)
            dfsHelper(graph , visited , verticesVisited , adjacentEdge.dest);
    }
}

vector <int> dfs(vector <vector <Edge> > &graph , vector <bool> &visited , int source) {

    vector <int> verticesVisited;
    dfsHelper(graph , visited , verticesVisited , source);
    return verticesVisited;
}

int main() {

    int vertices;
    cin >> vertices;
    
    int edges;
    cin >> edges;

    vector <vector <Edge> > graph(vertices);

    for(int i = 0; i < edges; i++) {
        int src , dest , wt;
        cin >> src >> dest >> wt;

        graph[src].push_back(Edge(src , dest , wt));
        graph[dest].push_back(Edge(dest , src , wt));
    }

    vector <bool> visited(vertices , false);
    vector <vector <int> > totalComponents;

    for(int i = 0; i < vertices; i++) {
        if(visited[i] == false) {
            vector <int> singleComponent = dfs(graph , visited , i);
            totalComponents.push_back(singleComponent);
        }
    }

    if(totalComponents.size() == 0) {
        cout << "No vertices has been visited";
    } else {
        for(int i = 0; i < totalComponents.size(); i++) {
            for(int j = 0; j < totalComponents[i].size(); j++) {
                cout << totalComponents[i][j] << " ";
            }
            cout << endl;
        }
    }
    cout << endl;

    return 0;
}