#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
#include <utility>
int main()
{
    /* imagine you have to check how many nodes are reachable if each node has a minimum amount of nodes that needs 
        to be reached by for counting it as valid a possible implementation of this problem can be using 
        a priority_queue for starting from the nodes that are already active and then refreshing it doing the same 
        until no more node are reachable*/
    std::ifstream cin("input.txt");
    std::ofstream cout("output.txt");
    int N,M,src;
    cin >> N;
    int minToValid[N] = {0};
    int reachedBy[N]= {0};
    bool processed[N] = {false};
    std::priority_queue<std::pair<int,int>> q;
    std::vector<int> edges[N];
    for(int i = 0; i < N; i++)
    {
        cin >> M >> minToValid[i];
        if(minToValid[i]==0)
        {
            q.push({minToValid[i],i});
            processed[i] = true;
        }

        for(int j = 0; j < M; j++)
        {
            cin >> src;
            edges[src].push_back(i);
        }
    }
    int start;
    while(!q.empty())
    {
        start = q.top().second;  
        q.pop();
        
        for(auto u: edges[start])
        {
            reachedBy[u]++;
            if(reachedBy[u]>=minToValid[u] && !processed[u])
            {
                processed[u] = true;
                q.push({reachedBy[u],u});
            }
        }
    }

    int tot = 0;
    for(int i = 0; i < N; i++)
    {
        if(processed[i])
        {
            tot++;
        }
    }
    cout << tot << std::endl;
    return 0;
}