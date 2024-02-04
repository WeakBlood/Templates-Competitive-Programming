#include <iostream>
#include <vector>
#include <cstring>

const int MOD = 1e9 + 7;
const int MAXN = 100005;



int countWays(int node,int N,std::vector<int> &dp,std::vector<bool> &visited,std::vector<std::vector<int>> &adj) {
    if (visited[node]) {
        return dp[node];
    }

    if (node == N) {
        return 1;
    }

    int ways = 0;

    for (int neighbor : adj[node]) {
        ways = (ways + countWays(neighbor,N,dp,visited,adj)) % MOD;
    }

    // Save the result in the dp array and mark the node as visited
    dp[node] = ways;
    visited[node] = true;

    return ways;
}

int main() {
    int N, M; // N: Number of nodes, M: Number of edges
    std::cin >> N >> M;
    std::vector<std::vector<int>> graph(N+1);
    std::vector<int> dp(N+1,0);
    std::vector<bool> visited(N+1,false);
    // Input the edges of the DAG
    for (int i = 0; i < M; ++i) 
    {
        int src, des;
        std::cin >> src >> des;
        graph[src].push_back(des);
    }

    // Calculate and print the number of ways to reach node N from node 1
    std::cout << countWays(1,N,dp,visited,graph) << std::endl;

    return 0;
}
