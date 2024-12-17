#include<iostream>
#include<vector>
using namespace std;

// Taking inputs without Weight
void inputsWithoutWeight(int numOfNodes, int numOfEdges, vector<vector<int>> &graph) {

    int node1, node2, weight;

    for(int i = 0; i < numOfEdges; ++i) {

        cin >> node1 >> node2;
        graph[node1].push_back(node2);
        graph[node2].push_back(node1);    // for undirected graph
    }
}

// Taking inputs with Weight
void inputsWithWeight(int numOfNodes, int numOfEdges, vector<vector<pair<int, int>>> &graph) {

    int node1, node2, weight;

    for(int i = 0; i < numOfEdges; ++i) {

        cin >> node1 >> node2 >> weight;
        graph[node1].push_back({node2, weight});
        graph[node2].push_back({node1, weight});    // for undirected graph
    }
}

void printList1(vector<vector<int>> &graph) {

    int numOfNodes = graph.size();

    for(int i = 1; i < numOfNodes; ++i) {
        
        cout << i << " --> ";
        for(int node : graph[i]) {
            cout << node << ", ";
        }
        cout << endl;
    }
}

void printList2(vector<vector<pair<int, int>>> &graph) {

    int numOfNodes = graph.size();

    for(int i = 1; i < numOfNodes; ++i) {
        
        cout << i << " --> ";
        for(auto node : graph[i]) {
            cout << "{"<< node.first << "-" << node.second << "}, ";
        }
        cout << endl;
    }
}

int main() {
    int numOfNodes, numOfEdges;
    cin >> numOfNodes >> numOfEdges;

    // vector<vector<int>> graph(numOfNodes + 1);
    // inputsWithoutWeight(numOfNodes, numOfEdges, graph);
    // printList1(graph);

    vector<vector<pair<int, int>>> graph(numOfNodes + 1);
    inputsWithWeight(numOfNodes, numOfEdges, graph);
    printList2(graph);

}