#include <vector>
#include <iostream>
#include <numeric>
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
int main()
{
    return 0;
}