#include <bits/stdc++.h>

long long paletta_sort(int N, int V[]);
void add(std::vector<long long int>& l, long long int idx, long long int val);
long long int check(std::vector<long long int>& l, long long int idx);
long long int count(std::vector<long long int> a, int N);
bool IsOrdinable(int N, int V[]);
long long paletta_sort(int N, int V[])
{
    if(!IsOrdinable(N, V)) return -1;

    long long int res = 0;
    std::vector<long long int> pari(ceil((float)N / 2));
    std::vector<long long int> dispari(N / 2);

    for(int i = 0; i < N; i += 2)
        pari[i / 2] = V[i];

    for(int i = 1; i < N; i += 2)
        dispari[i / 2] = V[i];

    res += count(pari, ceil((float)N / 2));
    res += count(dispari, N / 2);

    return res;
}

bool IsOrdinable(int N, int V[])
{
    bool ordin = true;
    for(int i = 0; i < N; i++)
        if(V[i] % 2 != i % 2)
        {
            ordin = false;
            break;
        }
    return ordin;
}

void add(std::vector<long long int>& l, long long int index, long long int valore)
{
    index += 1;
    while(index < l.size()){
        l[index] += valore;
        index += index & -index;
    }
}

long long int check(std::vector<long long int>& l, long long int index)
{
    index += 1;
    long long int somma = 0;
    while(index)
    {
        somma += l[index];
        index -= index & -index;
    }
    return somma;
}

long long int count(std::vector<long long int> a, int N)
{
    long long int res = 0;

    std::vector<long long int> l(N + 1, 0);
    std::vector<long long int> b = a;
    sort(b.begin(), b.end());
    for(int i = 0; i < N; i++)
        a[i] = std::lower_bound(b.begin(), b.end(), a[i]) - b.begin();

    for(int i = 0; i < N; i++)
    {
        add(l, a[i], 1);
        res += i - check(l, a[i]) + 1;
    }
    return res;
}

