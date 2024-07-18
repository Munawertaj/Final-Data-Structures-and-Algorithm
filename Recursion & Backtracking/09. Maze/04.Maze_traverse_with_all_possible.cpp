/*
    Problem Description: In this problem you have a 2D-maze where you can go down, right, up, left. Now count the total number of ways for reaching from start position(0, 0) to end position.
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

    // Considering this block as my path so make it 0 
    maze[row][col] = 0;
    
    // traverse towards down
    if(row < lastRowIndex)
        count = countPath(row + 1, col, count, maze);

    // traverse towards right
    if(col < lastColIndex)
        count = countPath(row, col + 1, count, maze);

    // traverse towards up
    if(row > 0)
        count = countPath(row - 1, col, count, maze);
    
    // traverse towards left
    if(col > 0)
        count = countPath(row, col - 1, count, maze);
    
    // this line is where the function will be over
    // so before the function gets removed, also remove the changes that were made by that function
    maze[row][col] = 1;
    
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

    // Considering this block as my path so make it 0 
    maze[row][col] = 0;
    
    // traverse towards down
    if(row < lastRowIndex)
        allPath = traverseMaze(row + 1, col, currentPath + 'D', allPath, maze);

    // traverse towards right
    if(col < lastColIndex)
        allPath = traverseMaze(row, col + 1, currentPath + 'R', allPath, maze);
    
    // traverse towards up
    if(row > 0)
        allPath = traverseMaze(row - 1, col, currentPath + 'U', allPath, maze);

    // traverse towards left
    if(col > 0)
        allPath = traverseMaze(row, col - 1, currentPath + 'L', allPath, maze);
    
    // this line is where the function will be over
    // so before the function gets removed, also remove the changes that were made by that function
    maze[row][col] = 1;

    return allPath;
}

int main() {


    vector<vector<int>> maze = {{1, 1, 1},
                                {1, 1, 1},
                                {1, 1, 1}}; // 0 represnts obstacle

    cout << countPath(0, 0, 0, maze) << endl;

    vector<string> allPath;
    string path = "";

    allPath = traverseMaze(0, 0, path, allPath, maze);

    return 0;
}