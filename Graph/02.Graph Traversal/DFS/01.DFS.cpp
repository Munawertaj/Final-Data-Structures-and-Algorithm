#include<iostream>
#include<vector>
using namespace std;

void dfs(int node, vector<vector<int>> &graph, vector<bool>& visited) 
{
    // Take action on node after entering that node
    visited[node] = true;

    for (int child : graph[node]) 
    {
        if (!visited[child]) 
        {
            // Take action on child-node before entering that child-node

            dfs(child, graph, visited);

            // Take action on child-node after exiting that child-node
        }
    }
    // Take action on node after entering that node
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

void printList(vector<vector<int>> &graph) 
{
    int numOfNodes = graph.size();

    for (int i = 1; i < numOfNodes; ++i) 
    {
        cout << i << " --> ";

        for (int node : graph[i]) 
        {
            cout << node << ", ";
        }

        cout << endl;
    }
}

int main() 
{
    int numOfNodes, numOfEdges;
    cin >> numOfNodes >> numOfEdges;

    vector<vector<int>> graph(numOfNodes + 1);
    vector<bool> visited(numOfNodes + 1);

    takeInputs(numOfNodes, numOfEdges, graph);
    printList(graph);

    dfs(1, graph, visited);

    return 0;  
}