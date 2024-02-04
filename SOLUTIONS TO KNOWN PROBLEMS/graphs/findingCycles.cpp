#include <iostream>
#include <vector>
#include <fstream>
#include <list>
#include <stack>
#define IOS std::ios_base::sync_with_stdio(false);std::cin.tie(0);std::cout.tie(0);

using namespace std;

bool findCycle(int node, const vector<list<int>> &graph, vector<int> &parent, vector<int> &visited, list<int> &path) {
    visited[node] = 1; // Mark as visited
    for (auto u : graph[node]) 
    {
        if (visited[u] == 0) { // Not visited
            parent[u] = node;
            if (findCycle(u, graph, parent, visited, path))
            {
                return true;
            } 
        } 
        else if (visited[u] == 1) 
        {
            int current = node;
            path.push_back(u);
            while (current != u) 
            {
                path.push_back(current);
                current = parent[current];
            }
            path.push_back(u); // Close the cycle
            return true; // Return immediately after finding a cycle
        }
    }
    visited[node] = 2; // Mark as fully explored
    return false;
}

int main() {
    IOS;
    int N, M, src, des;
    cin >> N >> M;

    vector<list<int>> graph(N + 1);
    vector<int> parent(N + 1, -1), visited(N + 1, 0);
    list <int> path;

    for (int i = 0; i < M; i++) {
        cin >> src >> des;
        graph[src].push_back(des);
    }

    for (int i = 1; i <= N && path.empty(); i++) {
        if (!visited[i]) 
        {
            if (findCycle(i, graph, parent, visited, path)) 
            {
                break;
                } // Stop after finding the first cycle
        }
    }

    if (!path.empty()) {
        cout << path.size() << endl;
        while(!path.empty())
        {
            cout << path.back() << " ";
            path.pop_back();
        }
    } else {
        cout << "IMPOSSIBLE" << endl;
    }

    return 0;
}
