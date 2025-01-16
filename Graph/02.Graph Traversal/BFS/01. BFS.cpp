#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void bfs(int sourceNode, vector<vector<int>> &graph) 
{
    int numOfNodes = graph.size();
    vector<bool> visited(numOfNodes, false);
    queue<int> bfsQueue;

    vector<int> parent(numOfNodes);
    vector<int> level(numOfNodes);

    bfsQueue.push(sourceNode);
    visited[sourceNode] = true;
    
    parent[sourceNode] = -1;
    level[sourceNode] = 0;

    while(!bfsQueue.empty())
    {
        int currNode = bfsQueue.front();
        bfsQueue.pop();

        cout << currNode << " -> "; // to print the order of the traversal of bfs

        for(int child : graph[currNode])
        {
            if(visited[child]) continue;

            bfsQueue.push(child);
            visited[child] = true;
            parent[child] = currNode;
            level[child] = level[currNode] + 1;
        }
    }

}


void printList(vector<vector<int>> &graph) 
{
    int numOfNodes = graph.size();

    for(int i = 1; i < numOfNodes; ++i) 
    {    
        cout << i << " --> ";

        for(int node : graph[i]) 
        {
            cout << node << ", ";
        }

        cout << endl;
    }
}

void solve() 
{
    int numOfNodes, numOfEdges;
    cin >> numOfNodes >> numOfEdges;

    vector<vector<int>> graph(numOfNodes);
    int node1, node2;

    for(int i = 0; i < numOfEdges; ++i) 
    {
        cin >> node1 >> node2;
        graph[node1].push_back(node2);
        graph[node2].push_back(node1);    // for undirected graph
    }

    // printList(graph);

    bfs(0, graph);
}



int main() 
{
    solve();
    return 0;  
}