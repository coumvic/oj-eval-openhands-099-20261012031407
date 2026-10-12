#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

// Function to perform BFS and calculate fish count in a connected water region
int bfs(vector<vector<int>>& grid, vector<vector<bool>>& visited, int i, int j, int m, int n) {
    queue<pair<int, int>> q;
    q.push({i, j});
    visited[i][j] = true;
    int fishCount = grid[i][j];
    
    // Directions for adjacent cells (up, down, left, right)
    vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    
    while (!q.empty()) {
        auto [x, y] = q.front();
        q.pop();
        
        // Check all four adjacent cells
        for (auto& dir : directions) {
            int newX = x + dir.first;
            int newY = y + dir.second;
            
            // Check if the new position is within bounds and is an unvisited water cell
            if (newX >= 0 && newX < m && newY >= 0 && newY < n && 
                grid[newX][newY] > 0 && !visited[newX][newY]) {
                visited[newX][newY] = true;
                fishCount += grid[newX][newY];
                q.push({newX, newY});
            }
        }
    }
    
    return fishCount;
}

int main() {
    int m, n;
    cin >> m >> n;
    
    // Read the grid
    vector<vector<int>> grid(m, vector<int>(n));
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }
    
    // Create a visited array to keep track of visited cells
    vector<vector<bool>> visited(m, vector<bool>(n, false));
    int maxFish = 0;
    
    // Iterate through each cell in the grid
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            // If the cell is water and not visited, perform BFS
            if (grid[i][j] > 0 && !visited[i][j]) {
                int fishCount = bfs(grid, visited, i, j, m, n);
                maxFish = max(maxFish, fishCount);
            }
        }
    }
    
    cout << maxFish << endl;
    
    return 0;
}