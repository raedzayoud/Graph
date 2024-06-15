#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#define ll long long
using namespace std;

const int N = 1e3;
bool vis [N][N];
int n, m, ans = 0;

bool isValide(int x, int y, vector<vector<char>>a) {
    return x >= 0 && x <= n && y >= 0 && y<=m&&!vis[x][y]&&a[x][y]!='#';
}
void dfs(int x,int y, vector<vector<char>>a) {
    vis[x][y] = true;
    if (isValide(x + 1, y,a)) {
        dfs(x + 1, y,a);
    }
    if (isValide(x - 1, y,a)) {
        dfs(x - 1, y,a);
    }
    if (isValide(x, y+1,a)) {
        dfs(x, y+1,a);
    }
    if (isValide(x, y-1,a)) {
        dfs(x, y-1,a);
    }
}



int main() {
    int ans = 0;
    cin >> n >> m;
    vector<vector<char>>a(n, vector<char>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (a[i][j]=='.'&&!vis[i][j]) {
                ans++;
                dfs(i, j,a);
            }
        }
    }
    cout << ans;


    return 0;
}
