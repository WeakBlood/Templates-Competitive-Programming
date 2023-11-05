#include <iostream>
#include <vector>
#include <utility>
#include <fstream>

// Function to find the maximum percentage for a given sum
// knapsack problem variation, maximizing the value while staying under a certain target
int findMaxPercentage(std::vector<int>& arr, std::vector<int>& percentage, int N, int TARGET) 
{
    std::vector<int> dp(TARGET + 1, 0);

    for (int i = 0; i < N; i++) 
    {
        for (int j = TARGET; j >= arr[i]; j--) 
        {
            dp[j] = std::max(dp[j], dp[j - arr[i]] + percentage[i]);
        }
    }

    return dp[TARGET];
}

int main() {
    int N, TARGET;
    std::ios_base::sync_with_stdio(false);
    std::ifstream cin("input.txt");
    std::ofstream cout("output.txt");
    cin >> N >> TARGET;
    std::vector<int> arr(N);
    std::vector<int> percentage(N);
    for (int i = 0; i < N; i++) {
        cin >> percentage[i] >> arr[i];
    }

    int maxPercentage = findMaxPercentage(arr, percentage, N, TARGET);

    cout << maxPercentage << std::endl;

    return 0;
}
