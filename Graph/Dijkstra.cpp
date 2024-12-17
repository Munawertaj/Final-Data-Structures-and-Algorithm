#include<bits/stdc++.h>
using namespace std;
int INF = INT_MAX;

int diajkstra(vector<vector<pair<int, int>>>& graph, int source, int destination)
{
    int nodes = graph.size();
    vector<bool> visited(nodes + 1, false);
    vector<int> distance(nodes + 1, INF);
    priority_queue<pair<int, int>, vector<pair<int,int>>, greater<pair<int, int>>> pq;

    pq.push({0, source});
    distance[source] = 0;

    while(!pq.empty())
    {
        pair<int, int> currNode = pq.top();
        pq.pop();

        int node = currNode.second;
        if(visited[node]) continue;
        visited[node] = true;

        for(auto child: graph[node])
        {
            int weight = child.first;
            int childNode = child.second;
            if(distance[node] + weight < distance[childNode])
            {
                distance[childNode] = distance[node] + weight;
                pq.push({distance[childNode], childNode});
            }
        }
    }

    return distance[destination];
}

void printPath(vector<int>& parent, int source, int destination)
{
    vector<int> path;
    int temp = destination;
    while(temp != -1)
    {
        path.push_back(temp);
        temp = parent[temp];
    }

    for(int i = path.size() - 1; i >= 0; --i)
    {
        cout << path[i] << " ";
    }
}

void diajkstraPath(vector<vector<pair<int, int>>>& graph, int source, int destination)
{
    int nodes = graph.size();
    vector<bool> visited(nodes + 1, false);
    vector<int> distance(nodes + 1, INF);
    vector<int> parent(nodes + 1, -1);
    priority_queue<pair<int, int>, vector<pair<int,int>>, greater<pair<int, int>>> pq;

    pq.push({0, source});
    distance[source] = 0;

    while(!pq.empty())
    {
        pair<int, int> currNode = pq.top();
        pq.pop();

        int node = currNode.second;
        if(visited[node]) continue;
        visited[node] = true;

        for(auto child: graph[node])
        {
            int childNode = child.second;
            int weight = child.first;
            

            if(distance[node] + weight < distance[childNode])
            {
                distance[childNode] = distance[node] + weight;
                pq.push({distance[childNode], childNode});
                parent[childNode] = node;
            }
        }
    }
    if(visited[destination])
        printPath(parent, source, destination);
    else
        cout << " -1";
}

void solve()
{
    int nodes, edges;
    cin >> nodes >> edges;
    vector<vector<pair<int, int>>> graph(nodes + 1);    // since 1 is start

    int node1, node2, weight;
    for(int i = 0; i < edges; ++i)
    {
        cin >> node1 >> node2 >> weight;
        graph[node1].push_back({weight, node2});
        graph[node2].push_back({weight, node1});    // For undirected graph
    }

    int source = 1, destination = nodes;

    diajkstraPath(graph, source, destination);
}

void solve()
{
    int nodes, edges;
    cin >> nodes >> edges;
    vector<vector<pair<int, int>>> graph(nodes + 1);    // since 1 is start

    int node1, node2, weight;
    for(int i = 0; i < edges; ++i)
    {
        cin >> node1 >> node2 >> weight;
        graph[node1].push_back({weight, node2});
        graph[node2].push_back({weight, node1});    // For undirected graph
    }

    int source = 1, destination = nodes;

    cout << diajkstra(graph, source, destination);
}

int main()
{
    solve();
}