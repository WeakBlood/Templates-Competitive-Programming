#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    int N;
    cin >> N;

    if(N>2)
    {
        vector<vector<char>> griglia(N, vector<char>(N));

        for (int i = 0; i < N; i++) 
        {
            for (int j = 0; j < N; j++) 
            {
                cin >> griglia[i][j];
            }
        }
    }
    else
    {
        cout << 1;
    }

    return 0;
}
