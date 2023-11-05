#include <iostream>
#include <fstream>
#include <vector>
#define INF 1e9
using namespace std;

vector<vector<int>> edges;
vector<bool> processed;
vector<int> edgeWeight;

int dfs(int s, int previous)
{
    if(processed[s])
    {
         return s;
    }
    processed[s] = true;
    int min = INF;
    int saved = s;
    for(auto u: edges[s])
    {
        if(edgeWeight[u] < min && previous != u)
        {
            min = edgeWeight[u];
            saved = u;
        } 
    }
    if(saved == s)
    {
        return s;
    }
    return dfs(saved, s);
}

int main() {
    ios_base::sync_with_stdio(false);
    ifstream cin("input.txt");
    ofstream cout("output.txt");
    int N, A;
    cin >> N >> A;
    edges.resize(N);
    processed.resize(N);
    edgeWeight.resize(N);
    for(int i = 0; i < N; i++)
    {
        cin >> edgeWeight[i];
    }
    int src;
    int des;
    for (int i = 0; i < A; ++i) 
    {
        cin >> src;
        cin >> des;
        edges[src].push_back(des);
        edges[des].push_back(src);
    }
    cout << dfs(0, 0) << endl;
    
    return 0;
}
