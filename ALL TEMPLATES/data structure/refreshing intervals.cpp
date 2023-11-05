#include <iostream>
#include <fstream>
#include <string>
#include <unordered_map>
#include <set>
/*we define a custom comparator for the set were, if the int  
is greater it goes first if the int are the same the smallest string (ASCII) goes first*/
struct CustomComparator {                                                                                   
    bool operator()(const std::pair<int, std::string>& lhs, const std::pair<int, std::string>& rhs) const 
    {
        if (lhs.first == rhs.first)     
        {
            return lhs.second < rhs.second;
        }
        return lhs.first > rhs.first; // Otherwise, sort by frequency in descending order
    }
};

int main() {
    // uncomment the following lines if you want to read/write from files
    std::ifstream cin("input.txt");
    std::ofstream cout("output.txt");

    int N, T;
    cin >> N >> T;
    std::set<std::pair<int, std::string>, CustomComparator> q; // we use the set like a priority queue were is possible to move into any part
    std::unordered_map<std::string, int> mappa; // we are going to use a map  for keeping track of the frequency of each hashtag and refresh the set if needed

    std::string hashtags[N];
    for (int i = 0; i < N; i++)
    {
        cin >> hashtags[i];
        mappa[hashtags[i]] = 0;
    }
    std::string mostFrequentHashtag;
    for(int i = 0; i < T; i++)
    {
        q.erase({mappa[hashtags[i]],hashtags[i]});
        mappa[hashtags[i]]++;                       //first iteratio for filling the set with the initial values
        q.insert({mappa[hashtags[i]],hashtags[i]});
    }
    auto it = q.begin();
    mostFrequentHashtag = it->second;
    cout << mostFrequentHashtag << std::endl;
    for(int i = 1; i <= N-T; i++)
    {
        q.erase({mappa[hashtags[i-1]],hashtags[i-1]});
        mappa[hashtags[i-1]]--;                        // int this part we only need to remove a point from the out-dated part of the window and add the new part this allow us to save a lot of time :D
        q.insert({mappa[hashtags[i-1]],hashtags[i-1]});
        q.erase({mappa[hashtags[i+T-1]],hashtags[i+T-1]});
        mappa[hashtags[i+T-1]]++;
        q.insert({mappa[hashtags[i+T-1]],hashtags[i+T-1]});
            auto it = q.begin();
        mostFrequentHashtag = it->second;
        cout << mostFrequentHashtag << std::endl;

    }

    return 0;
}