#include <iostream>
#include <fstream>
#include <queue>
#include <utility>
#define INF 1e9
int N, M,T;
int max(int a, int b)
{
    if(a > b) 
    {
        return a;
    }
    return b;
}
bool isValid(int i, int j) 
{
    return i >= 1 && i <= N && j >= 1 && j <= M;
}

int main() {
    std::ifstream cin("input.txt");
    std::ofstream cout("output.txt");
    cin >> T;
    for(int K = 1; K <= T; K++)
    {
        cin >> N >> M;
        int  grid[N+1][M+1];
        bool processed[N+1][M+1];
        int distance[N+1][M+1];
        for (int i = 1; i <= N; i++) 
        {
            for (int j = 1; j <= M; j++) 
            {
                cin >> grid[i][j];
                processed[i][j] = false;
                distance[i][j] = INF;
            }
        }

        std::priority_queue<std::pair<int,std::pair<int,int>>> q;
        q.push(std::make_pair(0,std::make_pair(1,1)));
        distance[1][1] = 0;
        int dirs[4][2] = {{0, 1}, {1, 0},{-1,0}, {0,-1}};
        while(!q.empty())
        {
            int i = q.top().second.first;
            int j = q.top().second.second;
            q.pop();
            if(processed[i][j])
            {
                continue;
            }
            processed[i][j] = true;
            for (int d = 0; d < 4; ++d) 
            {
                int ni = i + dirs[d][0];
                int nj = j + dirs[d][1];

                if (isValid(ni, nj) && max(std::abs(grid[i][j]-grid[ni][nj]),distance[i][j])  < distance[ni][nj]) 
                {
                    distance[ni][nj] = max(std::abs(grid[i][j]-grid[ni][nj]),distance[i][j]);
                    q.push(std::make_pair(-distance[ni][nj],std::make_pair(ni,nj)));
                }
            }
        }
        
        cout << "Case #" << K << ": " << distance[N][M] << std::endl;
    }

    return 0;
}
