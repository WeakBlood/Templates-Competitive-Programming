#include <fstream>
#include <iostream>
#include <vector>
#define ll long long int
#define INF 1e9
#define IOS std::ios_base::sync_with_stdio(false);std::cin.tie(0);std::cout.tie(0);


int min(int a, int b)
{
    return a < b ? a : b;
}
int max(int a, int b)
{
    return a > b ? a : b;
}
struct SegmentTree{

    std::vector<ll> tree;
    int n;
    SegmentTree(const std::vector<int> &v, int N)
    {
        tree.resize(N*4);
        buildTree(v,1,0,N-1);
    }

    void buildTree(const std::vector<int> &v, int index, int left, int right)
    {
        if(left == right)
        {
            tree[index] = v[left];
        }
        else
        {
            int half = (left + right) / 2;
            buildTree(v,index*2,left,half);
            buildTree(v,index*2+1,half+1,right);
            tree[index] = tree[index*2] + tree[index*2+1];
        }
    }
    
    ll sumSegment(int index, int start, int end, int left, int right)
    {
        if(left > right)
        {
            return 0;
        }
        if(start == left && end == right)
        {
            return tree[index];
        }
        int half = (start + end) / 2;
        return sumSegment(index*2,start,half,left,min(right,half)) +sumSegment(index*2+1,half+1,end,max(left,half+1),right);
    }

    void updateSegment(int index, int start, int end,int pos, int val)
    {
        if(start == end)
        {
            tree[index] = val;
        }
        else
        {
            int half = (start + end) / 2;
            if(pos <= half)
            {
                updateSegment(index*2,start,half,pos,val);
            }
            else
            {
                updateSegment(index*2+1,half+1,end,pos,val);
            }
            tree[index] = tree[index * 2] + tree[index * 2 + 1];
        }
    }
};
int main() 
{
    IOS;
    #ifdef LOCAL
    std::ifstream file("input.txt");
    std::cin.rdbuf(file.rdbuf());
    #endif
    int N,Q,u,first,second;
    std::cin >> N >> Q;
    std::vector<int> v(N);
    for(int i = 0; i < N; i++)
    {
        std::cin >> v[i];
    }

    SegmentTree segmento(v,N);

    for(int i = 0; i < Q; i++)
    {
        std::cin >> u >> first >> second;
        first--;
        if(u == 1)
        {
            segmento.updateSegment(1,0,N-1,first,second);  
        }
        else
        {
            second--;
            std::cout << segmento.sumSegment(1,0,N-1,first,second) << std::endl;
        }
    }
    return 0;
}
