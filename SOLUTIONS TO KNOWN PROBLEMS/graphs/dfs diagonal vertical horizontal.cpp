#include <iostream>
#include <vector>
#include <fstream>

std::vector<std::vector<char>> griglia;
std::vector<std::vector<bool>> processed;
int N, M;
long int maxCount = 2;  // Avoid using the name 'max'

bool isValid(int i, int j) {
    return i >= 0 && i < N && j >= 0 && j < M;
}

void dfs(int i, int j, int dir, long int cont) 
{
    processed[i][j] = true;
    int dirs[4][2] = {{1, -1}, {1, 0}, {1, 1}, {0, 1}};
    for (int d = 0; d < 4; ++d) 
    {
        int ni = i + dirs[d][0];
        int nj = j + dirs[d][1];

        if (isValid(ni, nj) && griglia[ni][nj] == griglia[i][j]) 
        {
            if (dir == d || dir == -1) 
            {
                if (!processed[ni][nj]) 
                {
                    dfs(ni, nj, d, cont + 1);
                }
                if (cont + 1 > maxCount) 
                {
                    maxCount = cont + 1;
                }
            } 
            else if (!processed[ni][nj]) 
            {
                dfs(ni, nj, d, 2);
            }
        }
    }
}

int main() {
    std::ifstream cin("input.txt");
    std::ofstream cout("output.txt");

    cin >> N >> M;
    griglia.resize(N);
    processed.resize(N);
    for (int i = 0; i < N; i++) {
        griglia[i].resize(M);
        processed[i].resize(M);
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) 
        {
            cin >> griglia[i][j];
            processed[i][j] = false;
        }
    }

    for (int i = 0; i < N; i++) 
    {
        for (int j = 0; j < M; j++) 
        {
            if (!processed[i][j]) 
            {
                processed[i][j] = true;
                dfs(i, j, -1, 1);
            }
        }
    }
    cout << maxCount << std::endl;

    return 0;
}
