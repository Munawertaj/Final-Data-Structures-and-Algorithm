#include<iostream>
#include<vector>
using namespace std;

// Taking inputs without Weight
void inputsWithoutWeight(int numOfNodes, int numOfEdges, vector<vector<int>> &graph) {

    int node1, node2, weight;

    for(int i = 0; i < numOfEdges; ++i) {

        cin >> node1 >> node2;
        graph[node1][node2] = 1;
        graph[node2][node1] = 1;    // for undirected graph
    }
}

// Taking inputs with Weight
void inputsWithWeight(int numOfNodes, int numOfEdges, vector<vector<int>> &graph) {

    int node1, node2, weight;

    for(int i = 0; i < numOfEdges; ++i) {

        cin >> node1 >> node2 >> weight;
        graph[node1][node2] = weight;
        graph[node2][node1] = weight;    // for undirected graph
    }
}

void printMatrix(vector<vector<int>> &graph) {

    int numOfNodes = graph.size();
    for(int i = 1; i < numOfNodes; ++i) {
        for(int j = 1; j < numOfNodes; ++j) {
            cout << graph[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    int numOfNodes, numOfEdges;
    cin >> numOfNodes >> numOfEdges;

    vector<vector<int>> graph(numOfNodes + 1, vector<int> (numOfNodes + 1, 0));

    inputsWithoutWeight(numOfNodes, numOfEdges, graph);
    // inputsWithWeight(numOfNodes, numOfEdges, graph);

    printMatrix(graph);

}