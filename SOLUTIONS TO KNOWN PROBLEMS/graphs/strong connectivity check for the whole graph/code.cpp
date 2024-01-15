#include <iostream>
#include <fstream>
#include <vector>
#include <queue>

void DFS(int v, const std::vector<std::vector<int>> &graph, std::vector<bool> &visited) {
    visited[v] = true;
    for(int i: graph[v])
        if(!visited[i])
            DFS(i, graph, visited);
}

std::pair<int,int> isStronglyConnected(int N, std::vector<std::vector<int>> &graph) {
    std::vector<bool> visited(N+1, false);

    // Step 1: Perform DFS from any vertex
    DFS(1, graph, visited);

    // If DFS does not visit all vertices, then return false
    for(int i = 1; i <= N; i++)
        if(!visited[i])
            return std::make_pair(1,i);

    // Step 2: Reverse the graph
    std::vector<std::vector<int>> adjT(N+1);
    for(int i = 1; i <= N; i++)
        for(int j: graph[i])
            adjT[j].push_back(i);

    // Mark all vertices as not visited for second DFS
    for(int i = 1; i <= N; i++)
        visited[i] = false;

    // Step 3: Perform DFS on reversed graph
    DFS(1, adjT, visited);

    // If second DFS does not visit all vertices, then return false
    for(int i = 1; i <= N; i++)
        if(!visited[i])
            return std::make_pair(i,1);

    return std::make_pair(0,0);
}

int main() 
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::ifstream cin("input.txt");
    std::ofstream cout("output.txt");
    int N,M,src,des;
    std::cin >> N >> M;
    std::vector<std::vector<int>> graph(N+1);
    for(int i  = 0; i < M; i++)
    {
        std::cin >> src >> des;
        graph[src].push_back(des);
    }
    std::pair<int,int> value = isStronglyConnected(N,graph);
    if(value.second!=0)
    {
        std::cout << "NO" << std::endl;
        std::cout << value.first << " " << value.second << std::endl;
        return 0;
    }
    std::cout << "YES" << std::endl;
    return 0;
}

