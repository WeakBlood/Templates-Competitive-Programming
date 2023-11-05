
#include <bits/stdc++.h>
std::string s;
void sieveOfEratosthenes(int N)
{
	bool prime[N+1];
	memset(prime, true, sizeof(prime));

	for (int p=2; p*p<=N; p++)
	{
		// If prime[p] is not changed, then it is a prime
		if (prime[p] == true)
		{
			// Update all multiples of p
			for (int i=p*2; i<=N; i += p)
				prime[i] = false;
		}
	}

	long long int tot = 0;
	for (int p=0; p<=N; p++)
    {
        if (prime[p])
        {
            //know you know that p is prime i will print it 
            std::cout << p << " ";
        }
    }
    std::cout << std::endl;
    return;
}

int main()
{
    int N;
    std::cin >> N;
    sieveOfEratosthenes(N);
    return 0;
}
