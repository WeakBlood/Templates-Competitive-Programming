  // NOTE: it is recommended to use this even if you don't understand the following code.

#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
#include <utility>
#define INF 1e9

// input data
int N, M, T;
struct Edge {
    long int des, w;
    bool hasBomb = false;
};
int main() {
//  uncomment the following lines if you want to read/write from files
    std::ios_base::sync_with_stdio(false);
	std::ifstream cin("input.txt");
	std::ofstream cout("output.txt");

    cin >> N >> M >> T;
    int temp[N];
    for(int i = 0; i < N; i++)
    {
        temp[i] = T;
    }
    int A,B,C,E;
	std::vector<Edge> edges[N];
 	std::priority_queue<std::pair<long int,long int>> q;
    bool processed[N] = {false};
    for (long int i = 0; i < M; ++i) 
	{
        cin >> A >> B >> C >> E;
		if(T<C && E == 1)
		{
			
		}
		else
		{
		  		Edge edge;
		  		edge.des = B;
		  		edge.w = C;
                if(E==1)
                {
                    edge.hasBomb = true;
                }
		        edges[A].push_back(edge);
		}

    }
    long int distance[N];
    for (long int i = 0; i < N; i++) {
        distance[i] = INF;
    }
    distance[0] = 0;
    q.push({0, 0});
    
    while (!q.empty()) 
	{
        long int nodo = q.top().second; 
        q.pop();
        if (processed[nodo]) continue;
        processed[nodo] = true;
        for (auto u : edges[nodo]) 
		{
            if (distance[nodo] + u.w < distance[u.des] && (temp[nodo] - u.w >=0|| u.hasBomb != true))
			{
                distance[u.des] = distance[nodo] + u.w;
                temp[u.des] = temp[u.des] - distance[u.des];
                q.push({-distance[u.des], u.des});
            }
        }
    } 
    if(distance[N-1]!=INF)
    {
    	cout << distance[N-1] << std::endl;
	}
	else 
	{
		cout << -1 << std::endl;
	}
    
    return 0;
}