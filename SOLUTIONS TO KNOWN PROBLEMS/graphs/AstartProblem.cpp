#include <iostream>
#include <queue>
#include <vector>
#include <unordered_map>

using namespace std;

struct Edge {
    int node;
    int weight;
};

struct CompareCost {
    bool operator()(const pair<int, int>& p1, const pair<int, int>& p2) {
        return p1.second > p2.second;
    }
};

vector<int> a_star_search(vector<vector<Edge>>& graph, int start, int goal) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, CompareCost> frontier;
    unordered_map<int, bool> explored;
    unordered_map<int, int> came_from;

    frontier.push({start, 0});

    while (!frontier.empty()) {
        pair<int, int> current = frontier.top();
        frontier.pop();

        if (current.first == goal) {
            vector<int> path;
            for (int node = goal; node != start; node = came_from[node]) {
                path.push_back(node);
            }
            path.push_back(start);  // Don't forget to add the start node
            reverse(path.begin(), path.end());  // Reverse the path to get it from start to goal
            return path;
        }

        if (!explored[current.first]) {
            explored[current.first] = true;

            for (Edge edge : graph[current.first]) {
                frontier.push({edge.node, current.second + edge.weight});
                came_from[edge.node] = current.first;
            }
        }
    }

    return {};  // Return an empty path if there is no path from start to goal
}

int main() {
    int num_nodes, num_edges;
    cin >> num_nodes >> num_edges;

    vector<vector<Edge>> graph(num_nodes);

    for (int i = 0; i < num_edges; i++) {
        int a, b, w;
        cin >> a >> b >> w;

        graph[a].push_back({b, w});
        graph[b].push_back({a, w});  // Remove this line if the graph is directed
    }

    int start, goal;
    cin >> start >> goal;

    vector<int> path = a_star_search(graph, start, goal);

    for (int node : path) {
        cout << node << ' ';
    }

    return 0;
}
