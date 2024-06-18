#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

vector<int>adj[100000];
void dfs(int pos, vector<bool>& vis) {
    vis[pos] = true;
    for (int i = 0; i < adj[pos].size(); i++) {
        int x = adj[pos][i];
        if (!vis[x]) {
            dfs(x,vis);
        }
    }
}

int main() {

    int x,y, a,b;
    cin >> x>>y;
    for (int i = 0; i < y; i++) {
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    int ans = 0;
    vector<int>ans1;
    vector<bool> vis(x+1, false);
    for (int i = 1; i <= x; i++) {
        if (!vis[i]) {
            ans1.push_back(i);
            ans++;
            dfs(i, vis);
        }
    }
    cout << ans-1 <<endl;
    for (int i = 1; i < ans1.size(); i++) {
        cout << ans1[i - 1] << " " << ans1[i] << endl;
    }
    



    return 0;
}
