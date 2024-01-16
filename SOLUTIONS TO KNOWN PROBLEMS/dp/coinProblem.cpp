#include <iostream>
#include <fstream>
#include <vector>

#define INF 1e9
int minCoins(std::vector<int> &coins, int N, int X)
{
	std::vector<int> table(X+1,INF);
	table[0] = 0;

	for (int i = 1; i <= X; i++) 
    {
		for (int j = 0; j < N; j++)
        {
            if (coins[j] <= i) 
            {
				int sub_res = table[i - coins[j]];
				if (sub_res != INF && sub_res + 1 < table[i])
                {
                    table[i] = sub_res + 1;
                }
			}
        }
			
	}
	if (table [X] == INF)
    {
        return -1;
    }
		

	return table[X];
}

int main()
{
    int N,X;
    std::cin >> N >> X;
    std::vector<int> coins(N);
    for(int i = 0; i < N; i++)
    {
        std::cin >> coins[i];
    }
	std::cout << minCoins(coins, N, X) << std::endl;
	return 0;
}
