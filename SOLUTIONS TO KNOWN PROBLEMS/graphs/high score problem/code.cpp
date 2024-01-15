#include <iostream>
#include <vector>
#include <limits>
#include <fstream>
#include <queue>
#define cin std::cin
#define cout std::cout
#define ll long long int
#define INF -1e18
struct Edge 
{
    int destination, weight;
};
 
void addEdge(std::vector<std::vector<Edge>>& graph, int source, int destination, int weight) 
{
    graph[source].push_back({destination, weight});
}
void corrupt(int src, std::vector<bool> &corrupted,const std::vector<std::vector<Edge>>& graph)
{
    std::queue<int> q;
    q.push(src);
    while(!q.empty())
    {
        int node = q.front();
        q.pop();
        for(auto u: graph[node])
        {
            if(!corrupted[u.destination])
            {
                corrupted[u.destination] = true;
                q.push(u.destination);
            }
        }
    }

}
bool bellmanFord(const std::vector<std::vector<Edge>>& graph, int source, std::vector<ll>& distances,int N) 
{
    distances.resize(N+1, INF);
    distances[source] = 0;
 
    for (int i = 1; i < N; ++i) 
    {
        for (int u = 1; u <= N; ++u) 
        {
            for (const Edge& edge : graph[u]) 
            {
                int v = edge.destination;
                int w = edge.weight;
                if (distances[u] != INF && distances[u] + w > distances[v]) 
                {
                    distances[v] = distances[u] + w;
                }
            }
        }
    }
    //after you perform the bellman ford algorithm you start a bfs for corrupting all the result that you had 
    //and that are actually corrupted so you can know wich of them is still valid 
    std::vector<bool> corrupted(N+1,false);
    for (int u = 1; u <= N; ++u) 
    {
        for (const Edge& edge : graph[u]) 
        {
            int v = edge.destination;
            int w = edge.weight;
            if (distances[u] != INF && distances[u] + w > distances[v]) 
            {
                corrupted[u] = true;
                corrupted[v] = true;
            }
        }
    }
    for(int i = 1; i <= N; i++)
    {
        if(corrupted[i])
        {
            corrupt(i,corrupted,graph);
        }
        if(corrupted[1] || corrupted[N])
        {
            return false;
        }
    }
    return true;
}
 
int main() {
    // Example graph
    int N,M,src,des,weight;
    //std::ifstream cin("input.txt");
    //std::ofstream cout("output.txt");
    cin >> N >> M;
    std::vector<std::vector<Edge>> graph(N+1);
    for(int i = 0; i < M; i++)
    {
        cin >> src >> des >> weight;
        addEdge(graph, src, des, weight);
    }
    int source = 1;
    std::vector<ll> distances;
 
    if(bellmanFord(graph,source,distances,N))
    {
        cout << distances[N] << std::endl;
    }
    else
    {
        cout << -1 << std::endl;
    }
    return 0;
}