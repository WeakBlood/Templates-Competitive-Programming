#include <iostream>
#include <fstream>
#include <vector>
#define INF 1e9
#define ll long long int 
using namespace std;

void floydWarshall(int N,vector<vector<ll>> &graph)
{

    for(int k = 0; k < N; k++)
    {
        for(int i = 0; i < N; i++)
        {
            for(int j = 0; j < N; j++)
            {
                if(graph[i][k] + graph[k][j] < graph[i][j])
                {
                    graph[i][j] = graph[i][k] + graph[k][j];
                }
            }
        }
    }
    
}

int main()
{

    ifstream cin("input.txt");

    int N,M,src,des,w;

    cin >> N >> M;  

    vector<vector<ll>> graph(N,vector<ll> (N,INF));
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < N; j++)
        {
            graph[i][j] = i == j ? 0 : graph[i][j];
        }
    }
    for(int i = 0; i < M; i++)
    {
        cin >> src >> des >> w;
        graph[src][des] = w;
    }
    floydWarshall(N,graph);
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < N; j++)
        {
            cout << graph[i][j] << " ";
        }
        cout << endl;
    }
    
    return 0;
}