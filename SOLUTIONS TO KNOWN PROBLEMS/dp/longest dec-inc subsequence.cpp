#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
int longest_decreasing_subsequence(const std::vector<int>& arr) 
{
    int n = arr.size();
    std::vector<int> tail(n, 0);
    int len = 1; // Length of the longest decreasing subsequence

    tail[0] = arr[0];

    for (int i = 1; i < n; ++i) 
    {
        
        auto it = std::lower_bound(tail.begin(), tail.begin() + len, arr[i], std::greater<int>());

        if (it == tail.begin() + len) 
        {
            // If arr[i] is greater than all elements in tail, append it to the end
            tail[len] = arr[i];
            len++;
        } 
        else 
        {
            // If arr[i] is not greater than all elements, replace the smallest element greater than or equal to arr[i]
            *it = arr[i];
        }
    }

    return len;
}

int main() {
    std::ifstream cin("input.txt");
    std::ofstream cout("output.txt");
    int N; 
    cin >> N; 
    std::vector<int> arr(N);
    for(int i = 0; i < N; i++)
    {
        cin >> arr[i];
    }
    int result = longest_decreasing_subsequence(arr);
    
    cout << result << std::endl;

    return 0;
}
