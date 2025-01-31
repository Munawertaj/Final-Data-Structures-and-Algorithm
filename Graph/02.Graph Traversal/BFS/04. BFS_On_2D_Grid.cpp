#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// Directions: up -> (-1, 0), down -> (1, 0), left -> (0, -1), right -> (0, 1)
vector<int> dx = {-1, 1, 0, 0};
vector<int> dy = {0, 0, -1, 1};

bool isValid(int row, int col, const vector<vector<int>>& grid)
{
    int numRows = grid.size();
    int numCols = grid[0].size();
    return (row >= 0 && row < numRows && col >= 0 && col < numCols && grid[row][col] == 1);
}

void bfsGridTraverse(int startRow, int startCol, vector<vector<int>>& grid)
{
    queue<pair<int, int>> bfsQue;
    bfsQue.push({startRow, startCol});
    grid[startRow][startCol] = 0;   // Marking this position as visited

    while (!bfsQue.empty())
    {
        auto [currRow, currCol] = bfsQue.front();
        bfsQue.pop();

        // Explore all 4 directions (up, down, left, right)
        for (int i = 0; i < 4; i++)
        {
            int newRow = currRow + dx[i];
            int newCol = currCol + dy[i];

            // Check if the new position is valid
            if (isValid(newRow, newCol, grid))
            {
                bfsQue.push({newRow, newCol});
                grid[newRow][newCol] = 0; // Mark as visited
            }
        }
    }
}

// Function to perform BFS traversal on the entire grid
void traverseGrid(vector<vector<int>>& grid)
{
    int rows = grid.size();
    int cols = grid[0].size();

    for (int r = 0; r < rows; r++)
    {
        for (int c = 0; c < cols; c++)
        {
            // If the current cell is open (1), start BFS
            if (grid[r][c] == 1)
            {
                bfsGridTraverse(r, c, grid);
            }
        }
    }
}

// Function to take inputs for the grid and call BFS
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

    // Perform BFS traversal on the grid
    traverseGrid(grid);
}

int main()
{
    solve();
    return 0;
}
