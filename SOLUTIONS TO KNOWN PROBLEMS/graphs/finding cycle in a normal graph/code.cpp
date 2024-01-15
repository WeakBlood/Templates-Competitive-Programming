#include<bits/stdc++.h>
using namespace std;

vector<int> adj[100001];
int vis[100001], par[100001];
vector<int> cycle;

bool dfs(int v, int p) {
    vis[v] = 1;
    for(int u : adj[v]) {
        if(u == p) continue;
        if(vis[u]) {
            cycle.push_back(v);
            while(v != u) {
                v = par[v];
                cycle.push_back(v);
            }
            cycle.push_back(cycle[0]);  // push the starting node again
            return true;
        }
        par[u] = v;
        if(dfs(u, par[u])) return true;
    }
    return false;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    for(int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    for(int i = 1; i <= n; i++) {
        if(!vis[i] && dfs(i, -1)) {
            cout << cycle.size() << "\n";
            for(int v : cycle) cout << v << " ";
            return 0;
        }
    }

    cout << "IMPOSSIBLE";
    return 0;
}
