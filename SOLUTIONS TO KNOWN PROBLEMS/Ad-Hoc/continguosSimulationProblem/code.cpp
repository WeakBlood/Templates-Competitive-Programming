#include <bits/stdc++.h>

using namespace std;


#define ll long long int
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    map<ll,ll> mappa;
    ll N,M,C,start;
    cin >> N >> M >> C;
    for(ll i = 0; i < N; i++)
    {
        cin >> start;
        if(start - M < 0)
        {
            mappa[0]++;
        }
        else
        {
            mappa[start-M]++;
        }
        mappa[start + M + 1]--;
    }

    ll count = 0;
    ll maxx= numeric_limits<ll>::max();
    if(mappa.begin()->first != 0)
    {   
        cout << 0 << endl;
        return 0;
    } 
    for(pair<ll,ll> u:mappa)
    {
        if(u.first <= C)
        {
            count += u.second;
            maxx = min(maxx,count);
        }
    }

    cout << maxx << endl;
    return 0;
}