#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <tuple>
#define ll size_t
struct Dsu 
{
    int n;
    std::vector<int> p, s;
    Dsu(int _n) : n(_n), p(_n), s(_n, 1) 
    {
        std::iota(begin(p), end(p), 0);
    }
    
    int find_set(int v) 
    {
        if(p[v] == v)
        {
            return v;
        }
        else
        {
            p[v] = find_set(p[v]);
            return p[v];
        }
    }
    bool union_set(int a, int b) 
    {
        a = find_set(a);
        b = find_set(b);
        if (a == b) 
        {
            return false;
        }
        if (s[a] < s[b]) 
        {
            std::swap(a, b);
        }
        p[b] = a;
        s[a] += s[b];
        return true;
    }
};

std::pair<ll,bool> kruskalMST(std::vector<std::tuple<int,int,int>> &edges, int N, int M)
{
    std::sort(edges.begin(),edges.end());
    Dsu myDsu(N);
    ll tot = 0;
    for(int i = 0; i < M; i++)
    {
        if(myDsu.union_set(std::get<1>(edges[i]),std::get<2>(edges[i])))
        {
            tot = tot + std::get<0>(edges[i]);
        }
    }
    int ref = myDsu.find_set(0);
    for(int i = 1; i < N; i++)
    {
        if(myDsu.find_set(i)!=ref)
        {
            return std::make_pair(tot,false);
        }
    }
    return std::make_pair(tot,true);
}

int main() 
{
    std::ios_base::sync_with_stdio(false);
    std::ifstream cin("input.txt");
    int N,M; 
    std::cin >> N >> M;
    std::vector<std::tuple<int,int,int>> edges(M);
    for(int i = 0; i < M; i++)
    {
        int src,des,w;
        std::cin >> src >> des >> w;
        edges[i] = std::make_tuple(w,src-1,des-1);
    }
    std::pair<ll,bool> values = kruskalMST(edges,N,M);
    if(!values.second)
    {
        std::cout << "IMPOSSIBLE" << std::endl;
    }
    else
    {
        std::cout << values.first << std::endl;
    }
    return 0;
}

