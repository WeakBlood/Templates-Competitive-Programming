#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
#define ll long long int
#define INF 1e18
using namespace std;

struct Edge{
    int des,w;
};

int main()
{
    ifstream cin("input.txt");
    int N,M,src,des,w;
    std::cin >> N >> M;

    vector<vector<Edge>> graph(N+1);
    for(int i = 0; i < M; i++)
    {
        std::cin >> src >> des >> w;
        graph[src].push_back({des,w});
    }

    vector<ll> dist1(N+1, INF), dist2(N+1, INF);
    priority_queue<pair<ll, pair<int, bool>>, vector<pair<ll, pair<int, bool>>>, greater<pair<ll, pair<int, bool>>>> pq;
    dist1[1] = 0;
    pq.push({0, {1, false}});

    while(!pq.empty())
    {
        ll d = pq.top().first;
        int v = pq.top().second.first;
        bool used = pq.top().second.second;
        pq.pop();

        if (used && d > dist2[v]) continue;
        if (!used && d > dist1[v]) continue;

        for(auto u: graph[v])
        {
            if(!used && dist1[v] + u.w < dist1[u.des])
            {
                dist1[u.des] = dist1[v] + u.w;
                pq.push({dist1[u.des], {u.des, false}});
            }
            if(dist1[v] + u.w/2 < dist2[u.des])
            {
                dist2[u.des] = dist1[v] + u.w/2;
                pq.push({dist2[u.des], {u.des, true}});
            }
            if(used && dist2[v] + u.w < dist2[u.des])
            {
                dist2[u.des] = dist2[v] + u.w;
                pq.push({dist2[u.des], {u.des, true}});
            }
        }
    }

    cout << dist2[N] << endl;
    return 0;
}
