#include <vector>
#include <fstream>
#include <iostream>
#include <unordered_set>
    std::vector<int> timeFound;
    std::vector<int> minTime;
    std::unordered_set<int> articulationP;
    std::vector<std::vector<int>> adj;
int min(int a, int b)
{
    if(a < b){return a;}return b;
}
    int timer = 0;
void dfs(int node, int parent)
{
    timer++;
    timeFound[node] = timer;
    minTime[node] = timer;
    int children = 0;
    for(auto u: adj[node])
    {
        if(u == parent)
        {
            continue;
        }
        if (timeFound[u] == -1)
        {
            dfs(u, node);
            minTime[node] = min(minTime[node], minTime[u]);
            if (minTime[u] >= timeFound[node] && parent!=0)
            {
                articulationP.insert(node);
            }
            children++;
        }
        else
        {
            minTime[node] = min(minTime[node], timeFound[u]);
        }


        if(parent == 0 && children > 1)
        {
            articulationP.insert(node);
        }
    }

}
int main()
{
    std::ifstream cin("input.txt");
    std::ofstream cout("output.txt");
    int N,M,src,des;
    cin >> N >> M;
    
    timeFound.assign(N+1,-1);
    minTime.assign(N+1,-1);
    adj.resize(N+1);
    for(int i = 0; i < M; i++)
    {
        cin >> src >> des;
        adj[src].push_back(des);
        adj[des].push_back(src);
    }
    dfs(1,0);
    cout << "Numero di nodi: " << articulationP.size() << std::endl;
    for(auto u: articulationP)
    {
        cout << "Il nodo : " << u << " è un articolation point" << std::endl;
    }
    cout << std::endl;
    return 0;
}
