#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;


bool isCycleExists(int sourceNode, vector<bool>& visited, vector<vector<int>> &graph) 
{
    int numOfNodes = graph.size();
    vector<int> parent(numOfNodes);
    queue<int> bfsQueue;

    bfsQueue.push(sourceNode);
    visited[sourceNode] = true;
    parent[sourceNode] = -1;

    while (!bfsQueue.empty())
    {
        int currNode = bfsQueue.front();
        int parentNode = parent[currNode];
        bfsQueue.pop();

        for (int child : graph[currNode])
        {
            if (!visited[child])
            {
                bfsQueue.push(child);
                visited[child] = true;
                parent[child] = currNode;
            }

            else if (child != parentNode)   // if visited and it is not parent
            {
                // it means other node had visited this before and it's a cycle
                return true;
            }
        }
    }

    return false;
}

void solve() 
{
    int numOfNodes, numOfEdges;
    cin >> numOfNodes >> numOfEdges;

    vector<vector<int>> graph(numOfNodes);
    int node1, node2;

    for (int i = 0; i < numOfEdges; ++i) 
    {
        cin >> node1 >> node2;
        graph[node1].push_back(node2);
        graph[node2].push_back(node1);    // for undirected graph
    }

    vector<bool> visited(numOfNodes, false);

    for(int i = 0; i < numOfNodes; i++)
    {
        if (isCycleExists(i, visited, graph))
        {
            cout << "Cycle Exists..";
            return;
        }
    }
    
    cout << "Cycle doesn't exist!!!";

}



int main() 
{
    solve();
    return 0;  
}