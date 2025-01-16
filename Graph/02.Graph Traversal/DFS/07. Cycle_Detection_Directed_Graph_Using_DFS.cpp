#include<iostream>
#include<vector>
using namespace std;

bool cycleDetect(int currNode, vector<bool>& visited, vector<bool>& pathVisited, vector<vector<int>> &graph)
{
    bool isLoopExists = false;

    visited[currNode] = true;
    pathVisited[currNode] = true;

    for (int child : graph[currNode]) 
    {
        if (pathVisited[child]) return true;

        if (!visited[child]) 
        {
            isLoopExists = isLoopExists | cycleDetect(child, visited, pathVisited, graph);
        }
    }
    
    pathVisited[currNode] = false;
    return isLoopExists;
}

// Taking inputs without Weight
void takeInputs(int numOfNodes, int numOfEdges, vector<vector<int>> &graph) 
{
    int node1, node2;

    for (int i = 0; i < numOfEdges; ++i) 
    {
        cin >> node1 >> node2;
        graph[node1].push_back(node2);// for directed graph  
    }
}

bool isCycle(vector<vector<int>>& graph) 
{
    int numOfNodes = graph.size();
    vector<bool> visited(numOfNodes + 1);
    vector<bool> pathVisited(numOfNodes + 1);
    

    for (int i = 0; i < numOfNodes; ++i) 
    {
        if (!visited[i]) 
        {
            if (cycleDetect(i, visited, pathVisited, graph)) return true;
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