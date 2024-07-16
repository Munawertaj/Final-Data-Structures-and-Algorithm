/*
    Problem Description: In this problem you have a 2D-maze where you can go right, down and corner. Now count the total number of ways for reaching from start position(0, 0) to end position.
*/

#include<iostream>
#include<vector>
#include<string>
using namespace std;

int countAllPath(int row, int col, int count) {

    if(row == 1 && col == 1) {
        count++;
        return count;
    }
    
    // traverse towards corner until it is on the last column
    if(col > 1 && row > 1)
        count = countAllPath(row - 1, col - 1, count);

    // traverse towards right until it is on the last column
    if(col > 1)
        count = countAllPath(row, col - 1, count);
    
    // traverse towards down until it is on the last row
    if(row > 1)
        count = countAllPath(row - 1, col, count);
    
    return count;
}

vector<string> traverseMaze(int row, int col, string currentPath, vector<string>& allPath) {

    if(row == 1 && col == 1) {
        cout << currentPath << endl;
        allPath.push_back(currentPath);
        return allPath;
    }

    // traverse towards corner until it is on the last column
    if(col > 1 && row > 1)
        allPath = traverseMaze(row - 1, col - 1, currentPath + 'C', allPath);

    // traverse towards right until it is on the last column
    if(col > 1)
        allPath = traverseMaze(row, col - 1, currentPath + 'R', allPath);
    
    // traverse towards down until it is on the last row
    if(row > 1)
        allPath = traverseMaze(row - 1, col, currentPath + 'D', allPath);
    
    return allPath;
}

int main() {

    int row = 3, col = 3;

    cout << countAllPath(row, col, 0) << endl;

    vector<string> allPath;
    string path = "";

    allPath = traverseMaze(row, col, path, allPath);

    return 0;
}