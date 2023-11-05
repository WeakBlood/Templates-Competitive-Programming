#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
#include <utility>
#define INF 1e9
using namespace std;

struct Edge 
{
     int des;
};

int main() {
    ifstream cin("input.txt");
	ofstream cout("output.txt");
    int N, M;
    cin >> N >> M;
    vector<Edge> edges[N];
    bool processed[N + 1] = {false};
    int a = 0;
    for ( int i = 0; i < M; ++i) 
	{
        int src;
        cin >> src;
        a = src;
        Edge edge;
        cin >> a;
        edge.des = a;
        edges[src].push_back(edge);
        Edge ede;
        ede.des = src;
        edges[a].push_back(ede);
    }
    
    cout << 0<< endl;
    
    return 0;
}