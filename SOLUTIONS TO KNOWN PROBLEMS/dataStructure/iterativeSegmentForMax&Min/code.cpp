#include <bits/stdc++.h>

using namespace std;

#define INF 1e9
struct Values{
    int max = -1;
    int min = INF;
};
struct EasySeg{
    int N;
    vector<Values> tree;

    EasySeg(vector<int> &vet):N(vet.size())
    {
        tree.resize(N*2);
        for(int i = 0; i < N; i++)
        {
            tree[i+N].max = vet[i];
            tree[i+N].min = vet[i];
        }

        for(int i = N-1; i >= 0; i--)
        {
            tree[i].max = max(tree[i*2].max,tree[i*2+1].max);
            tree[i].min = min(tree[i*2].min,tree[i*2+1].min);
        }
    }

    Values findIt(int l, int r)
    {
        Values values;

        for(l+=N,r+=N; l < r; l>>=1, r>>=1)
        {
            if(l & 1)
            {
                values.min = min(values.min,tree[l].min);
                values.max = max(values.max,tree[l].max);
                l++;
            }
            if(r & 1)
            {
                --r;
                values.min = min(values.min,tree[r].min);
                values.max = max(values.max,tree[r].max);
            }
        }
        return values;
    }
};
int main()
{
    ifstream cin("input.txt");
    ofstream cout("output.txt");
    int N,K;
    cin >> N >> K;
    vector<int> vet(N);

    for(int i = 0; i < N; i++)
    {
        cin >> vet[i];
    }

    EasySeg mySegment(vet);

    int massimo = 0;
    for(int i = 0; i < N; i++)
    {
        Values values = mySegment.findIt(i,min(i+K+1,N));
        massimo = max(massimo,values.max - values.min);
    }
    cout << massimo << endl;
    return 0;
}