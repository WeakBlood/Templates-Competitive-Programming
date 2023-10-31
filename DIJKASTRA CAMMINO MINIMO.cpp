#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
#include <utility>
#define INF 1e9
using namespace std;

struct Edge {
     int des, w;
};

int main() {
    ifstream cin("input.txt");
	ofstream cout("output.txt");
    int N, M, T, AIR;
    cin >> N >> M >> T >> AIR;
    vector<Edge> edges[N + 1];
    priority_queue<pair< int, int>> q;
    bool processed[N + 1] = {false};
    bool aired[N+1] = {false};
    int n;
    for(int i = 1; i <= AIR; i++)
    {
        cin >> n;
        aired[n] = true;
    }
    int a = 0;
    int weight = 0;
    for ( int i = 1; i <= M; ++i) 
	{
        int src;
        cin >> src;
        a = src;
        Edge edge;
        cin >> a;
        cin >> weight;
        edge.des = a;
        edge.w = weight;
        edges[src].push_back(edge);
        Edge ede;
        ede.des = src;
        ede.w = weight;
        edges[a].push_back(ede);
    }
    int distance[N+1] = {INF};
    distance[1] = 0;
    q.push({0, 1});
    
    while (!q.empty()) 
	{
         int nodo = q.top().second; 
        q.pop();
        if (processed[nodo]) continue;
        processed[nodo] = true;
        for (auto u : edges[nodo]) 
		{
            if (distance[nodo] + u.w < distance[u.des]) 
			{
                distance[u.des] = distance[nodo] + u.w;
                q.push({-distance[u.des], u.des});
            }
        }
    }
    
    cout << distance[N] << endl;
    
    return 0;
}