#include <bits/stdc++.h>
using namespace std;

#define ll long long int
struct simpleTree{
    int N;
    vector<ll> tree;

    simpleTree(){}
    simpleTree(vector<int> vet): N(vet.size())
    {
        tree.resize(N*2);

        for(int i =0; i < N; i++)
        {
            tree[i+N] = vet[i];
        }

        for(int i = N - 1; i > 0; i--)
        {
            tree[i] = max(tree[i*2],tree[i*2+1]);
        }
    }
    void updateTree(int idx, int val)
    {
        for(tree[idx+=N] = val; idx > 1; idx >>= 1)
        {
            tree[idx>>1] = max(tree[idx],tree[idx^1]);
        }
    }

    ll queryTree(int left, int right)
    {
        ll massimo = 0;

        for(left+=N,right+=N; left < right; left >>= 1, right >>= 1)
        {
            if(left & 1)
            {
                massimo = max(massimo,tree[left++]);
            }
            if(right & 1)
            {
                massimo = max(massimo,tree[--right]);
            }
        }

        return massimo;
    }
};

struct HLD{
    int N;
    int cur_position = 0;
    vector<int> parents,position,size,depth,head;

    vector<vector<int>> graph;
    simpleTree mySegment;

    HLD(vector<vector<int>> graph, vector<int> &values): N(graph.size()),graph(graph)
    {
        parents.assign(N,-1);position.assign(N,-1);
        size.assign(N,0);depth.assign(N,-1);
        head.assign(N,-1);
        dfs(0);
        decompose(0,0);
        mySegment = simpleTree(vector<int> (N,0));
        for(int i = 0; i < N; i++)
        {
            mySegment.updateTree(position[i],values[i]);
        }
    }

    int dfs(int node)
    {
        for(int &u:graph[node])
        {
            if(u != parents[node])
            {
                parents[u] = node;
                depth[u] = depth[node] + 1;
                size[node]+=dfs(u);
            }
        }

        sort(graph[node].begin(),graph[node].end(), [&](int a, int b){return size[a] > size[b];});
        return size[node];
    }

    void decompose(int node, int h)
    {
        head[node] = h;
        position[node] = cur_position++;
        bool heavyFound = false;

        for(int u:graph[node])
        {
            if(u == parents[node])
            {
                continue;
            }
            if(!heavyFound)
            {
                heavyFound = true;
                decompose(u,h);
            }
            else
            {
                decompose(u,u);
            }
        }

    }

    ll query(int a, int b)
    {
        ll ans = 0;
        
        while(head[a] != head[b])
        {
            if(depth[head[a]] > depth[head[b]])
            {
                swap(a,b);
            }
            ans = max(ans,mySegment.queryTree(position[head[b]],position[b]+1));
            b = parents[head[b]];
        }
        if(depth[a] > depth[b])
        {
            swap(a,b);
        }
        ans = max(ans,mySegment.queryTree(position[a],position[b]+1));
        return ans;
    }

    void update(int idx, int val)
    {
        mySegment.updateTree(position[idx],val);
    }
};

int main()
{
      ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifdef LOCAL
    ifstream cin("input.txt");
    #endif
    int N,Q,src,des,type;
    cin >> N >> Q;
    vector<int> vet(N);
    vector<vector<int>> graph(N);
    for(int i = 0; i < N; i++)
    {
        cin >> vet[i];
    }

    for(int i = 1; i < N; i++)
    {
        cin >> src >> des;
        src--;des--;
        graph[src].push_back(des);
        graph[des].push_back(src);
    }
    
    HLD myHdl(graph,vet);
    for(int i = 0; i < Q; i++)
    {
        cin >> type;
        
        if(type == 1)
        {
            int k,x;
            cin >> k >> x;
            k--;
            myHdl.update(k,x);
            //update to x k--
        }
        else
        {
            int a,b;
            cin >> a >> b;
            a--; b--;
            cout << myHdl.query(a,b) << " ";
            //max path
        }
    }
    return 0;
}