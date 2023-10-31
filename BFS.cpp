#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
#define INF 1e9
/*BFS DI UN GRAFO NON DIRETTO  ++ CONTROLLI VARI */

int main() {
    std::ifstream cin("input.txt");
	std::ofstream  cout("output.txt");
    int N, M,src,des,max,x;
    cin >> N >> M;
    std::vector<int> edges[N];
    std::queue<int> q;
    x = 0; //nodo dal quale iniziamo
    max = 0; //registriamo il massimo numero di nodi collegati
    bool processed[N] = {false};
    for ( int i = 0; i < M; ++i) 
	{
        cin >> src;
        cin >> des;
        edges[src].push_back(des);
        if(edges[src].size() > max)
        {
            max = edges[src].size();
            x = src;
        }
        edges[des].push_back(src);
        if(edges[des].size() > max)
        {
            max = edges[des].size();
            x = src;
        }

    }
    bool allGood = true; // facciamo una verifica che tutti i nodi siano collegati con il nodo di starting
    q.push(x);
    processed[x] = true;
    while(!q.empty()) //effettiva BFS
    {
        int s = q.front();
        q.pop();
        for(auto u: edges[s])
        {
            if(processed[u]) continue;
            processed[u] = true;
            q.push(u);
        }
    }
    for(int i = 0; i < N; i++)
    {
        if(!processed)
        {
            //nodo non connesso al nodo x
        }
    }
    cout << 0 << std::endl;
    
    return 0;
}
