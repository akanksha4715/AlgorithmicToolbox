#include <iostream>
long long pisano(long long m)
{
    long prev, curr, res;
    prev = 0;
    curr = 1;
    res = 0;
    for (long long i = 0; i < m * m; i++)
    {
        long temp = curr;
        curr = (prev + curr) % m;
        prev = temp;
        if (prev == 0 && curr == 1)
        {
            res = i + 1;
        }
    }

    return res;
}
int fibo_sum(long long n)
{
    if (n <= 1)
        return n;
    long long period = 60;
    n = n % period;
    if (n <= 1)
        return n;
    long long previous = 0;
    long long current = 1;
    long long sum = 1;
    for (int i = 0; i < n - 1; i++)
    {
        long long temp = previous;
        previous = current;
        current = (temp + current) % 10;
        sum += current;
        sum = sum;
    }
    return sum % 10;
}
/*int fibonacci_sum_naive(unsigned long long n)
{
    if (n <= 1)
        return n;

    unsigned long long previous = 0;
    unsigned long long current = 1;
    unsigned long long sum = 1;

    for (long long i = 0; i < n - 1; ++i)
    {
        unsigned long long tmp_previous = previous;
        previous = current;
        current = (tmp_previous + current) % 10;
        sum += current;
        sum = sum % 10;
    }

    return sum;
}
*/
int main()
{
    unsigned long long n = 0;
    std::cin >> n;
    std::cout << fibo_sum(n);
}
