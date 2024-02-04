#include <iostream>
#include <vector>
#include <fstream>
#define INF 1e9
struct Edge {
    int destination;
    int weight;
};
void addEdge(std::vector<std::vector<Edge>> &graph, int source, int des, int w)
{
    graph[source].push_back({des,w});
}

void bellmanFord(const std::vector<std::vector<Edge>>& edges, int source,int N) 
{
    std::vector<int> distance(N, INF);
    distance[source] = 0;

    for (int i = 0; i < N-1; ++i) 
    {
        for (int u = 1; u <= N; ++u) 
        {
            for (const Edge& edge : edges[u]) 
            {
                int v = edge.destination;
                int w = edge.weight;
                if (distance[u] != INF && distance[u] + w < distance[v]) 
                {
                    distance[v] = distance[u] + w;
                }
            }
        }
    }

    // Check for negative weight cycles
    for (int u = 1; u <= N; ++u) 
    {
        for (const Edge& edge : edges[u]) 
        {
            int v = edge.destination;
            int w = edge.weight;
            if (distance[u] != INF && distance[u] + w < distance[v]) {
                std::cout << "Graph contains negative weight cycle\n";
                return;
            }
        }
    }

    // Print the distances
    std::cout << "Shortest distances from source " << source << ":\n";
    for (int i = 1; i <= N; ++i) 
    {
        if (distance[i] == INF) 
        {
            std::cout << "Vertex " << i << ": INFINITY\n";
        } 
        else 
        {
            std::cout << "Vertex " << i << ": " << distance[i] << "\n";
        }
    }
}

int main() {
    std::ifstream cin("input.txt");
    std::ofstream cout("output.txt");
    int N,M,src,des,w;
    cin >> N >> M;
    std::vector<std::vector<Edge>> edges(N+1);
    for(int i = 0; i < M; i++)
    {
        cin >> src >> des >> w;
        addEdge(edges,src,des,w);
    }
    int sourceNode = 1;
    bellmanFord(edges, sourceNode,N);

    return 0;
}
