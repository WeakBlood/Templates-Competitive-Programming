#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm> // Added for std::max
#define INF 1e9

void addEdge(std::vector<std::vector<int>> &graph, int src, int des)
{
    graph[src].push_back(des);
}

int dp(int node, std::vector<std::vector<int>> &graph, std::vector<int> &memo)
{
    if (memo[node] == -1)
    {
        int max = 0;
        for (auto u : graph[node])
        {
            int next = dp(u, graph, memo);
            if (max < next)
            {
                max = next;
            }
        }
        memo[node] = max + 1;
    }
    return memo[node];
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::ifstream cin("input.txt");
    std::ofstream cout("output.txt");
    int N, M, src, des;
    cin >> N >> M;
    std::vector<std::vector<int>> graph(N+1);
    for (int i = 0; i < M; i++)
    {
        cin >> src >> des;
        addEdge(graph, src, des);
    }

    std::vector<int> memo(N + 1, -1);
    int max = 0;
    int node = -1;
    for (int i = 1; i <= N; i++)
    {
        int next = dp(i, graph, memo);
        if(max < next)
        {
            max = next;
            node = i;
        }
    }

    cout << max-1 << " " << node << std::endl;
    return 0;
}
