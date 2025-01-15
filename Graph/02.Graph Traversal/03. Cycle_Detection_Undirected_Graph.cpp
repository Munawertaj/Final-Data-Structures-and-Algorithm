#include<iostream>
#include<vector>
using namespace std;

bool cycleDetect(int currNode, int parent, vector<bool>& visited, vector<vector<int>> &graph)
{
    visited[currNode] = true;
    bool isLoopExists = false;

    for (int child : graph[currNode]) 
    {
        if (visited[child] && child != parent) return true;

        if (!visited[child]) 
        {
            isLoopExists = isLoopExists | cycleDetect(child, currNode, visited, graph);
        }
    }
    
    return isLoopExists;
}

// Taking inputs without Weight
void takeInputs(int numOfNodes, int numOfEdges, vector<vector<int>> &graph) 
{
    int node1, node2;

    for (int i = 0; i < numOfEdges; ++i) 
    {
        cin >> node1 >> node2;
        graph[node1].push_back(node2);
        graph[node2].push_back(node1);    // for undirected graph
    }
}

bool isCycle(vector<vector<int>>& graph) 
{
    int numOfNodes = graph.size();
    vector<bool> visited(numOfNodes + 1);
    

    for (int i = 0; i < numOfNodes; ++i) 
    {
        if (!visited[i]) 
        {
            if (cycleDetect(i, -1, visited, graph)) return true;
        }
    }
    
    return false;
}

int main() 
{
    int numOfNodes, numOfEdges;
    cin >> numOfNodes >> numOfEdges;

    vector<vector<int>> graph(numOfNodes + 1);

    takeInputs(numOfNodes, numOfEdges, graph);

    // cout << numOfNodes << " " << numOfEdges << endl;

    bool ans = isCycle(graph);

    if (ans) 
    {
        cout << "Cycle Exists";
    }
    else
    {
        cout << "Cycle Not Exists";
    } 

    return 0;  
}