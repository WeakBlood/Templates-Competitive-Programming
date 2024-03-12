#include <bits/stdc++.h>

using namespace std;


struct Segment{
    int N;
    vector<int> tree;

    Segment(const vector<int> &vet):N(vet.size())
    {
        tree.resize(N*4);
        buildUpTree(1,0,N-1,vet);
    }

    void buildUpTree(int idx, int start, int end, const vector<int> &vet)
    {
        if(start == end)
        {
            tree[idx] = vet[start];
        }
        else
        {
            int half = (start + end) / 2;
            buildUpTree(idx*2,start,half,vet);
            buildUpTree(idx*2+1,half+1,end,vet);
            tree[idx] = max(tree[idx*2],tree[idx*2+1]);
        }
    }


pair<int,int> lowerBoundSeg(int idx, int start, int end, int x) 
{
    if(start == end) 
    {
        if(tree[idx] >= x) 
        {
            return {tree[idx], start}; 
        }
        return {-1, -1};
    }

    int half = (start + end) / 2;
    if(tree[idx*2] >= x) 
    {
        return lowerBoundSeg(idx*2, start, half, x); 
    } 
    else if(tree[idx*2 + 1] >= x) 
    {
        return lowerBoundSeg(idx*2 + 1, half + 1, end, x); 
    }
    return {-1, -1};
}


    void updateSegment(int idx, int start, int end, int target, int value)
    {
        if(start == end)
        {
            tree[idx] = value;
        }
        else
        {
            int half = (start + end) / 2;

            if(target <= half)
            {
                updateSegment(idx*2,start,half,target,value);
            }
            else
            {
                updateSegment(idx*2+1,half+1,end,target,value);
            }
            tree[idx] = max(tree[idx*2],tree[idx*2+1]);
        }
    }
};
int main()
{
    int N,Q;

    cin >> N >> Q;

    vector<int> vet(N);
    for(int i = 0; i < N; i++)
    {
        cin >> vet[i];
    }

    Segment mySegment(vet);

    for(int i = 0; i < Q; i++)
    {
        int targ;
        cin >> targ;
        pair<int,int> save = mySegment.lowerBoundSeg(1,0,N-1,targ);
        cout << save.second+1 << " ";
        if(save.second != -1)
        {
            mySegment.updateSegment(1,0,N-1,save.second,save.first - targ);
        }
    }
    return 0;

}