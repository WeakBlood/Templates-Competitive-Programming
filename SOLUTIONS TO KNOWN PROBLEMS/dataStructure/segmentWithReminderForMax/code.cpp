#include <bits/stdc++.h>

using namespace std;

#define ll long long int
bool hasChanged = false;
struct simpleSegment{
    int N;
    vector<int> tree;
    vector<unordered_map<int,ll>> saved;
    simpleSegment(int N_)
    {
        for (N = 1; N < N_; N <<= 1);
        tree.resize(N*2);
        saved.resize(N);

    }


    void update(int pos, int value) 
    {
        for (tree[pos += N] = value; pos > 1; pos >>= 1) 
        {
            tree[pos >> 1] = max(tree[pos], tree[pos ^ 1]);
            saved[pos >> 1].clear();
        }
    }

    ll sum (int idx, int x)
    {
        if(idx >= N*2)
        {
            return 0;
        }
        if(tree[idx] <= x)
        {
            return 0;
        }
        if(idx >= N)
        {
            return tree[idx];
        }
        if(saved[idx].count(x) != 0)
        {
            return saved[idx][x];
        }
        return saved[idx][x] = sum(idx*2, max(x,tree[idx*2+1])) + sum(idx*2+1,x);
    }
};
int main()
{
    int N,Q;
    cin >> N >> Q;
    simpleSegment Tree(N);
    for(int i = 0; i < N; i++)
    {
        int num;
        cin >> num;
        Tree.update(i,num);
    }

    for(int i = 0; i < Q; i++)
    {
        int pos,val;
        cin >> pos >> val;
        Tree.update(pos,val);
        cout << Tree.sum(1,-1) << endl;
    }
    return 0;   
}