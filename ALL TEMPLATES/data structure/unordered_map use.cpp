#include <fstream>
#include <iostream>
#include <vector>
#include <unordered_map>

/* THIS CODE IS AN EXAMPLE OF POSSIBLE USE FOR AN UNORDERED MAP WERE WE USE THEM TO TAKE CARE 
    OF THE POSITION OF THE CAR AND THE NUMBER OF TIME THAT IT SWAPPED!
*/
int main() {
    // uncomment the following lines if you want to read/write from files
    std::ifstream cin("input.txt");
    std::ofstream cout("output.txt");
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    int N, Q;
    cin >> N >> Q;

    std::vector<int> C(N);
    std::unordered_map<int, int> pos;
    for (int i = 0; i < N; i++) 
    {
        cin >> C[i];
        pos[C[i]] = i;
    }

    std::unordered_map<int,int> swapCount;
    int maxSwaps = 0;
    int mostSwappedNumber = N+1;

    for (int i = 0; i < Q; i++) 
    {
        int x;
        cin >> x;
        int saved = pos[x];
        int mostSwapped = C[saved-1];
        swapCount[mostSwapped]++;
        if (swapCount[mostSwapped] > maxSwaps) 
        {
            maxSwaps = swapCount[mostSwapped];
            mostSwappedNumber = mostSwapped;
        } 
        else if (swapCount[mostSwapped] == maxSwaps && mostSwapped < mostSwappedNumber) 
        {
            mostSwappedNumber = mostSwapped;
        }
        std::swap(C[saved-1],C[saved]);
        pos[C[saved]] = saved;
        pos[C[saved-1]] = saved-1;
    	cout << mostSwappedNumber << std::endl;
    }
    return 0;
}