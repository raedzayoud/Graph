#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

const int N = 1000;
int n, m;
vector<vector<char>> grid;
vector<vector<bool>> visited(N, vector<bool>(N, false));
string shortestPath = "";
int shortestLength = INT_MAX;

bool isValid(int x, int y) {
    return x >= 0 && x < n && y >= 0 && y < m && !visited[x][y] && grid[x][y] != '#';
}

void dfs(int x, int y, string path) {
    if (grid[x][y] == 'B') {
        if (path.length() < shortestLength) {
            shortestLength = path.length();
            shortestPath = path;
        }
        return;
    }

    visited[x][y] = true;

    // Move Down
    if (isValid(x + 1, y)) {
        dfs(x + 1, y, path + 'D');
    }
    // Move Up
    if (isValid(x - 1, y)) {
        dfs(x - 1, y, path + 'U');
    }
    // Move Right
    if (isValid(x, y + 1)) {
        dfs(x, y + 1, path + 'R');
    }
    // Move Left
    if (isValid(x, y - 1)) {
        dfs(x, y - 1, path + 'L');
    }

    visited[x][y] = false; // Backtrack
}

int main() {
    cin >> n >> m;
    grid.resize(n, vector<char>(m));
    pair<int, int> start, end;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> grid[i][j];
            if (grid[i][j] == 'A') {
                start = { i, j };
            }
            else if (grid[i][j] == 'B') {
                end = { i, j };
            }
        }
    }

    dfs(start.first, start.second, "");

    if (shortestPath != "") {
        cout << "YES" << endl;
        cout << shortestLength << endl;
        cout << shortestPath << endl;
    }
    else {
        cout << "NO" << endl;
    }

    return 0;
}
