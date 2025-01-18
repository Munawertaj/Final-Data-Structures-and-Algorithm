#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

vector<int> backtrackPath(int node, vector<int>& parent)
{
    vector<int> path;
    
    while (node != -1)
    {
        path.push_back(node);
        node = parent[node];
    }

    reverse(path.begin(), path.end());
    return path;
}

vector<int> shortestPathUsingBFS(int sourceNode, int destination, vector<vector<int>> &graph) 
{
    int numOfNodes = graph.size();
    vector<bool> visited(numOfNodes, false);
    queue<int> bfsQueue;

    vector<int> parent(numOfNodes);
    vector<int> level(numOfNodes, -1);  // -1 represent it is impossible to reach from source to destination

    bfsQueue.push(sourceNode);
    visited[sourceNode] = true;
    parent[sourceNode] = -1;
    level[sourceNode] = 0;

    while (!bfsQueue.empty())
    {
        int currNode = bfsQueue.front();
        bfsQueue.pop();


        for (int child : graph[currNode])
        {
            if (visited[child]) continue;

            bfsQueue.push(child);
            visited[child] = true;
            parent[child] = currNode;
            level[child] = level[currNode] + 1;
        }
    }

    if (!visited[destination]) return {};    // If it is impossible to reach from source to destination
    
    return backtrackPath(destination, parent);
}

void printPath(vector<int>& path)
{
    if (path.size() == 0)
    {
        cout << "Path not exists!!!";
        return;
    }

    for (int node: path)
    {
        cout << node << " -> ";
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

    int source, destination;
    cin >> source >> destination;
    vector<int> path = shortestPathUsingBFS(source, destination, graph);

    printPath(path);
}



int main() 
{
    solve();
    return 0;  
}