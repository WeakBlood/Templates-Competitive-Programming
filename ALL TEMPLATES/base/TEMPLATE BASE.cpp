#include <iostream>
#include <fstream>
void UnaFunzione(int N)
{

}
int main() {
    int N;
    std::ifstream cin("input.txt");
    std::ofstream cout("output.txt");
    cin >> N;
    cin.close();
    cout.close();

    return 0;
}
