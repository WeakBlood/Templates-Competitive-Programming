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
    int N, M;
    cin >> N >> M;
    vector<Edge> edges[N];
    priority_queue<pair< int, int>> q;
    bool processed[N] = {false};
    int distance[N];
    int n;
    int a = 0;
    int weight = 0;
    /*qui stiamo usando una versione di inizializzazione che va in entrambi i versi per avere una versione diretta usa:
        int src;
        for ( int i = 1; i <= M; ++i) 
        {
            cin >> src;
            Edge edge;
            cin >> edge.des;
            cin >> edge.w;
            edges[src].push_back(edge);
        }
    */
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
    /* non usiamo la dicitura "distance[N] = INF; poichè causa errori quindi limitiamoci a questa" */
    for(int i = 0; i < N; i++)
    {
        distance[i] = INF;
    }
    distance[0] = 0;
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
