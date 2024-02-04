#include <vector>
#include <fstream>
#include <iostream>
std::vector<int> timeFound;
std::vector<int> minTime;
std::vector<std::pair<int,int>> bridges;
std::vector<std::vector<int>> adj;
int min(int a, int b)
{
    if(a < b){return a;}return b;
}
int timer = 0;
void dfs(int node, int parent)
{
    timeFound[node] = timer;
    minTime[node] = timer;
    timer++;
    for (auto u : adj[node])
    {
        if (u == parent)
            continue; 

        if (timeFound[u] == -1)
        {
            dfs(u, node);
            minTime[node] = min(minTime[node], minTime[u]);

            if (minTime[u] > timeFound[node])
            {
                bridges.push_back({node,u});
            }
        }
        else
        {
            minTime[node] = min(minTime[node], timeFound[u]);
        }
    }
}
int main()
{
    std::ifstream cin("input.txt");
    std::ofstream cout("output.txt");
    int N,M,src,des;
    cin >> N >> M;
    
    timeFound.assign(N,-1);
    minTime.assign(N,-1);
    adj.resize(N);
    for(int i = 0; i < M; i++)
    {
        cin >> src >> des;
        adj[src].push_back(des);
        adj[des].push_back(src);
    }
    for(int i = 0; i < N; i++)
    {
        if(timeFound[i]==-1)
        {
            dfs(i,i);
        }
        
     }

     for(auto u: bridges)
     {
        cout << "L'arco che connette : " << u.first << " con : " << u.second << " è un bridge"<< std::endl;
     }
    return 0;
}
