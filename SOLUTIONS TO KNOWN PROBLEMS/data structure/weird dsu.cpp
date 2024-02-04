#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
#include <vector>
#include <iostream>
#include <numeric>
int massimo(int a, int b, int c)
{
    if(a > b && a > c)
    {
        return a;
    }
    else if(b > a && b > c)
    {
        return b;
    }
    return c;
}
struct Dsu 
{
    int n;
    std::vector<int> p, s;
    int components;
    int max = -1;
    Dsu(int _n) : n(_n), p(_n), s(_n, 1) 
    {
        components = n-1;
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
    std::pair<int,int> union_set(int a, int b) 
    {
        a = find_set(a);
        b = find_set(b);
        if (a == b) 
        {
            max = massimo(s[a],s[b],max);
            return std::make_pair(components,max);
        }
        if (s[a] < s[b]) 
        {
            std::swap(a, b);
        }
        p[b] = a;
        s[a] += s[b];
        max = massimo(s[a],s[b],max);
        components--;
        return std::make_pair(components,max);
    }
};
int main()
{
    std::ifstream cin("input.txt");
    int N,M,src,des;
    std::cin >> N >> M;
    Dsu myStruct(N+1);
    for(int i = 0; i < M; i++)
    {
        std::cin >> src >> des;
        std::pair<int,int> values = myStruct.union_set(src,des);
        std::cout << values.first << " " << values.second << std::endl;
    }
    return 0;
}