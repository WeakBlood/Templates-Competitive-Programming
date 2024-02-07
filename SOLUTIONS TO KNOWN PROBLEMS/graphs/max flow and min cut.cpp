#include <iostream>
#include <vector>
#include <queue>
#include <list>
 
#define INF 1e17
#define ll long long int
using namespace std;
ll min(ll a, ll b)
{
    return a < b ? a:b;
}
ll bfs(int s, int t, vector<int> &parent,const vector<list<int>> &graph, const vector<vector<ll>> &capacity)
{
    for(size_t i = 0; i <  parent.size(); i++)
    {
        parent[i] = -1;
    }
    parent[s] = -2;
    queue<pair<int,ll>> q;
    q.push({s,INF});
    while(!q.empty())
    {
        int cur = q.front().first;
        ll flow = q.front().second;
        q.pop();
 
        for(int next : graph[cur])
        {
            if(parent[next] == -1 && capacity[cur][next])
            {
                parent[next] = cur;
                ll new_flow = min(flow,capacity[cur][next]);
                if(next == t)
                {
                    return new_flow;
                }
                q.push({next,new_flow});
            }
        }
    }
    return 0;
}
 
void max_flow(int s, int t, int N,const vector<list<int>> &graph,vector<vector<ll>> &capacity )
{
    ll flow = 0;
    vector<int> parent(N);
    ll new_flow;
 
    while(new_flow = bfs(s,t,parent,graph,capacity))
    {
        flow = flow + new_flow;
        int cur = t;
        while(cur != s)
        {
            int prev = parent[cur];
            capacity[prev][cur] = capacity[prev][cur] - new_flow;
            capacity[cur][prev] = capacity[cur][prev] + new_flow;
            cur = prev;
        }
    }
    return;
 
}
void bfs_residual(int s, const vector<vector<ll>>& capacity, const vector<list<int>>& graph, vector<bool>& visited) 
{
    queue<int> q;
    q.push(s);
    visited[s] = true;
    while (!q.empty()) 
    {
        int u = q.front();
        q.pop();
        for (int v : graph[u]) 
        {
            if (!visited[v] && capacity[u][v] > 0) 
            { // Check for positive residual capacity
                q.push(v);
                visited[v] = true;
            }
        }
    }
}
 
vector<pair<int, int>> find_min_cut(int s, int t, const vector<vector<ll>>& capacity, const vector<list<int>>& graph, int N) {
    vector<bool> visited(N+1, false);
    bfs_residual(s, capacity, graph, visited); 
    vector<pair<int, int>> min_cut;
    for (int u = 1; u <= N; ++u) 
    {
        if (visited[u]) {
            for (int v : graph[u]) 
            {
                if (!visited[v] && capacity[u][v] <= 0) 
                { 
                    min_cut.push_back({u, v});
                }
            }
        }
    }
    return min_cut;
}
int main()
{
 
    int N,M,src,des,cap;
    cin >> N >> M;
 
 
    vector<vector<ll>> capacity(N+1,vector<ll> (N+1,0));
    vector<list<int>> graph(N+1);
    cap = 1;
    for(int i = 0; i < M; i++)
    {
        cin >> src >> des;
        graph[src].push_back(des);
        graph[des].push_back(src);
        capacity[src][des] = capacity[src][des] + cap;
        capacity[des][src] = capacity[des][src] + cap;
    }
    max_flow(1,N,N+1,graph,capacity);
    vector<pair<int,int>> cuts = find_min_cut(1,N,capacity,graph,N);
    cout << cuts.size() << endl;
 
    for(size_t i = 0; i < cuts.size(); i++)
    {
        cout << cuts[i].first << " " << cuts[i].second << endl;
    }
 
    return 0;
}