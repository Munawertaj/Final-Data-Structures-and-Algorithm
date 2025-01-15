#include <iostream>
#include <vector>
using namespace std;

// Directions: up -> (-1, 0), down -> (1, 0), left -> (0, -1), right -> (0, 1)
vector<int> dx = {-1, 1, 0, 0};
vector<int> dy = {0, 0, -1, 1};

bool isValid(int row, int col, vector<vector<int>>& grid)
{
    int numRows = grid.size();
    int numCols = grid[0].size();

    return (row >= 0 && row < numRows && col >= 0 && col < numCols);
}


void dfsGridTraverse(int currRow, int currCol, vector<vector<bool>>& visited, vector<vector<int>>& grid, vector<pair<int, int>>& path)
{
    visited[currRow][currCol] = true;
    path.push_back({currRow, currCol});  // Add the current cell to the path

    // Explore all 4 directions (up, down, left, right)
    for (int i = 0; i < 4; i++)
    {
        int newRow = currRow + dx[i];
        int newCol = currCol + dy[i];

        // Check if the new position is valid and unvisited, and if the cell is open (1)
        if (isValid(newRow, newCol, grid) && !visited[newRow][newCol] && grid[newRow][newCol] == 1)
        {
            dfsGridTraverse(newRow, newCol, visited, grid, path);
        }
    }
}

// Function to print the path
void printPath(const vector<pair<int, int>>& path)
{
    for (int i = 0; i < path.size(); ++i)
    {
        cout << "(" << path[i].first << ", " << path[i].second << ")";
        if (i != path.size() - 1) 
            cout << " -> "; // Print '->' between the coordinates
    }
    cout << endl;
}

// Function to perform DFS traversal on the entire grid
void traverseGrid(vector<vector<int>>& grid)
{
    int rows = grid.size();
    int cols = grid[0].size();

    vector<vector<bool>> visited(rows, vector<bool>(cols, false));

    for (int r = 0; r < rows; r++)
    {
        for (int c = 0; c < cols; c++)
        {
            // If the current cell is unvisited and open (1), start DFS
            if (!visited[r][c] && grid[r][c] == 1)
            {
                vector<pair<int, int>> path;
                dfsGridTraverse(r, c, visited, grid, path);
                printPath(path);
            }
        }
    }
}

// Function to take inputs for the grid and call DFS
void solve()
{
    int numRows, numCols;
    cin >> numRows >> numCols;

    vector<vector<int>> grid(numRows, vector<int>(numCols));

    // Take input for grid values
    for (int r = 0; r < numRows; r++)
    {
        for (int c = 0; c < numCols; c++)
        {
            cin >> grid[r][c];
        }
    }

    // Perform DFS traversal on the grid
    traverseGrid(grid);
}

int main()
{
    solve();
    return 0;
}
