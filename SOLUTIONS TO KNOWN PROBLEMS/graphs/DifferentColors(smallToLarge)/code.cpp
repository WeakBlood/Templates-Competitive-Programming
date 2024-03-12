#include <iostream>
#include <fstream>
#include <vector>
#include <set>
#include <list>
using namespace std;

vector<int> colors;
vector<list<int>> graph;
vector<int> sizes;
set <int> dfs(int node, int parent)
{
    set<int> s;
    for(int u:graph[node])
    {
        if(u != parent)
        {
            auto tmp = dfs(u,node);

            if(tmp.size() > s.size())
            {
                swap(tmp,s);
            }

            for(int color:tmp)
            {
                s.insert(color);
            }
        }
    }

    s.insert(colors[node]);
    sizes[node] = s.size();
    return s;
}
int main()
{

    int N,M,src,des;

    cin >> N;

    colors.resize(N+1);
    graph.resize(N+1);
    sizes.resize(N+1);

    for(int i = 1; i <= N; i++)
    {
        cin >> colors[i];
    }

    for(int i = 0; i < N-1; i++)
    {
        cin >> src >> des;
        graph[src].push_back(des);
        graph[des].push_back(src);
    }
    
    dfs(1,1);
    for(int i = 1; i <= N; i++)
    {
        cout << sizes[i] << " ";
    }
    return 0;
}