#include <bits/stdc++.h>

using namespace std;

#define ll long long int
struct simpleSegment{
    int N;
    vector<ll> tree;

    simpleSegment(int N_, const vector<int> &vet):N(N_)
    {
        tree.resize(N*2);

        for(int i = 0; i < N; i++) tree[i+N] = vet[i];
        for(int i = N-1; i > 0; i--) tree[i] = tree[i*2] + tree[i*2+1];

    }

    void update(int pos, int val)
    {
        for(tree[pos+=N] = val; pos > 1; pos>>=1)
        {
            tree[pos>>1] = tree[pos] + tree[pos^1];
        }
    }

    ll query(int l, int r)
    {
        ll sum = 0;

        for(l+=N,r+=N; l < r; l>>=1, r>>=1)
        {
            if(l & 1) sum += tree[l++];
            if(r & 1) sum += tree[--r];
        }
        return sum;
    }
};
int main()
{
    #ifdef LOCAL
    ifstream cin("input.txt");
    #endif

    int N;

    return 0;
}