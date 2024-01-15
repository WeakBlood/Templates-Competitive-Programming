#include <iostream>
#include <fstream>
#include <vector>
const int MOD = 1e9+7;


bool v(int j, int i, int N,const std::vector<std::vector<int>> &grid)
{
    return i < N && j < N && grid[i][j]!=-1;
}
int paths(std::vector<std::vector<int>> &grid, int N)
{

    grid[N-1][N-1] = 1;

    for(int i = N - 1; i >= 0; i--)
    {
        for(int j = N-1; j >= 0; j--)
        {
            if(grid[i][j] == -1)
            {
                continue;
            }
            if(v(j+1,i,N,grid))
            {
                grid[i][j] =  (grid[i][j] + grid[i][j+1]) % MOD;
            }
            if(v(j,i+1,N,grid))
            {
                grid[i][j] = (grid[i][j] + grid[i+1][j]) % MOD;
            }

        }
    }
    return grid[0][0];
}
int main()
{
    std::ifstream cin("input.txt");
    int N;
    char car;
    std::cin >> N;
    std::vector<std::vector<int>> grid(N,std::vector<int> (N,0));
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < N; j++)
        {
            std::cin >> car;
            if(car=='*')
            {
                if((i==0 && j == 0)||(i==N-1&&j==N-1))
                {
                    std::cout << 0 << std::endl;
                    return 0;
                }

                grid[i][j] = -1;
            }
        }
    }

    std::cout << paths(grid,N) << std::endl;
    return 0;
}