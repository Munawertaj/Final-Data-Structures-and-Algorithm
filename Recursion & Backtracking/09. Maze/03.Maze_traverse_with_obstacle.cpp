/*
    Problem Description: In this problem you have a 2D-maze where you can go right, down and corner. Now count the total number of ways for reaching from start position(0, 0) to end position.
*/

#include<iostream>
#include<vector>
#include<string>
using namespace std;

int countPath(int row, int col, int count, vector<vector<int>>& maze) {

    int lastRowIndex = maze.size() - 1;
    int lastColIndex = maze[0].size() - 1;

    if(row == lastRowIndex && col == lastColIndex) {
        count++;
        return count;
    }

    // If obstacle found just return
    if(!maze[row][col])  
        return count;

    // traverse towards corner until it is on the last column
    if(col < lastColIndex && row < lastRowIndex)
        count = countPath(row + 1, col + 1, count, maze);

    // traverse towards right until it is on the last column
    if(col < lastColIndex)
        count = countPath(row, col + 1, count, maze);
    
    // traverse towards down until it is on the last row
    if(row < lastRowIndex)
        count = countPath(row + 1, col, count, maze);
    
    return count;
}

vector<string> traverseMaze(int row, int col, string currentPath, vector<string>& allPath, vector<vector<int>>& maze) {

    int lastRowIndex = maze.size() - 1;
    int lastColIndex = maze[0].size() - 1;

    if(row == lastRowIndex && col == lastColIndex) {
        cout << currentPath << endl;
        allPath.push_back(currentPath);
        return allPath;
    }

    if(!maze[row][col])  // If obstacle found just return
        return allPath;

    // traverse towards corner until it is on the last column
    if(col < lastColIndex && row < lastRowIndex)
        allPath = traverseMaze(row + 1, col + 1, currentPath + 'C', allPath, maze);

    // traverse towards right until it is on the last column
    if(col < lastColIndex)
        allPath = traverseMaze(row, col + 1, currentPath + 'R', allPath, maze);
    
    // traverse towards down until it is on the last row
    if(row < lastRowIndex)
        allPath = traverseMaze(row + 1, col, currentPath + 'D', allPath, maze);
    
    return allPath;
}

int main() {


    vector<vector<int>> maze = {{1, 1, 0},
                                {1, 0, 1},
                                {1, 1, 1}}; // 0 represnts obstacle

    cout << countPath(0, 0, 0, maze) << endl;

    vector<string> allPath;
    string path = "";

    allPath = traverseMaze(0, 0, path, allPath, maze);

    return 0;
}