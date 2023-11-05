// NOTE: it is recommended to use this even if you don't understand the following code.

#include <cassert>
#include <iostream>
#include <vector>
#include <stack>
// constraints
#define MAXN 400000


// input data
int N, K, T, i, t;
std::vector<int>P;
/* the brackets problem is a problem that wants us to tell if a sentence is well parentisized 
	for checking that we can just use stack in the following way so that the pantesis will automatically "collapse"*/
int main() {
    //  uncomment the following lines if you want to read/write from files
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	
    assert(std::cin >> T);
    for(t = 0; t < T; t++) 
	{
        assert(std::cin >> N >> K);
        P.resize(N);
        for(i = 0; i < N; i++) {
            assert(std::cin >> P[i]);
        }
	    std::stack<int> stack;
		for(i = 0; i < N; i++)
		{
			if(!stack.empty())
			{
				if(stack.top()==P[i])
				{
					stack.pop();
				}
				else
				{
					stack.push(P[i]);
				}
			}
			else
			{
				stack.push(P[i]);
			}
		}
		if(stack.empty())
		{
			std::cout << 1 << std::endl; // all the parentesis found the corrispondent one 
		}
		else
		{
			std::cout << 0 << std::endl; // not well 
		}
    }
    return 0;
}