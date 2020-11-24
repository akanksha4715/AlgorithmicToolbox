#include <iostream>
#include <vector>
#include <cmath>
using std::vector;
using namespace std;
vector<long> optimal_summands(long n)
{
    vector<long> summands;
    if (n <= 2)
    {
        summands = {n};
    }
    else
    {
        long i = (sqrt(1 + 8 * n) - 1) / 2;
        //cout << i << endl;
        long sum = 0;
        long j;
        for (j = 0; j < i - 1; j++)
        {
            sum += (j + 1);
            summands.push_back(j + 1);
        }
        summands.push_back(n - sum);
    }
    //write your code here
    return summands;
}

int main()
{
    long n;
    std::cin >> n;
    vector<long> summands = optimal_summands(n);
    std::cout << summands.size() << '\n';
    for (size_t i = 0; i < summands.size(); ++i)
    {
        std::cout << summands[i] << ' ';
    }
    std::cout << endl;
}
