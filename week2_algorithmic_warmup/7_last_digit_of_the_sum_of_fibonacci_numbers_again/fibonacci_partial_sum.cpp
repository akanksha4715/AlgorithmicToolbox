#include <iostream>
#include <vector>
using std::vector;
using namespace std;

long long get_fibonacci_partial_sum_naive(long long from, long long to)
{
    int temp;
    from = from % 60;
    to = to % 60;
    if (to >= from)
    {

        long long sum = 0;

        long long current = 0;
        long long next = 1;

        for (long long i = 0; i <= to; ++i)
        {
            if (i >= from)
            {
                sum += current;
                sum = sum % 10;
            }

            long long new_current = next;
            next = (next + current) % 10;
            current = new_current % 10;
        }

        return sum % 10;
    }
    else
    {
        //cout << to << from;

        long long sum = 0;

        long long current = 0;
        long long next = 1;

        next = 1;
        for (long long i = 0; i <= 59; ++i)
        {
            if (i > to && i < from)
            {
            }
            else
            {
                sum += current;
                sum = sum % 10;
            }
            long long new_current = next;
            next = (next + current) % 10;
            current = new_current % 10;
        }

        return sum % 10;
    }
}

int main()
{
    long long from, to;
    std::cin >> from >> to;
    std::cout << get_fibonacci_partial_sum_naive(from, to) << '\n';
}
