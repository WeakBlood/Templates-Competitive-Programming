#include <iostream>
#include <fstream>
#include <list>
#include <vector>


using namespace std;

void sortingDfs(int node, const vector<list<int>> &graph, list<int> &order, vector<bool> &visited)
{
    visited[node] = true;

    for(auto u: graph[node])
    {
        if(!visited[u])
        {
            sortingDfs(u,graph,order,visited);
        }
    }
    order.push_back(node);
}

void checkingDfs(int node, const vector<list<int>> &rGraph, list<int> &components, vector<bool> &visited)
{
    visited[node] = true;
    components.push_back(node);
    for(auto u:rGraph[node])
    {
        if(!visited[u])
        {
            checkingDfs(u,rGraph,components,visited);
        }
    }
}
int main()
{
    ifstream cin("input.txt");
    int N,M,src,des;


    cin >> N >> M;

    vector<list<int>> graph(N);
    vector<list<int>> revGraph(N);
    for(int i = 0; i < M; i++)
    {
        cin >> src >> des;

        graph[src].push_back(des);
        revGraph[des].push_back(src);
    }

    list<int> components;
    list<int> order;
    vector<bool> visited(N,false);

    for(int i = 0; i < N;i++)
    {
        if(!visited[i])
        {
            sortingDfs(i,graph,order,visited);
        }
    }

    visited.assign(N,false);

    while(!order.empty())
    {
        int start = order.back();
        order.pop_back();
        if(!visited[start])
        {
            checkingDfs(start,revGraph,components,visited);
            
            while(!components.empty())
            {
                cout << components.front() <<  " ";
                components.pop_front();
            }
            cout << endl;
        }
    }
    return 0;
}