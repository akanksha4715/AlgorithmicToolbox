#include <iostream>
using namespace std;
int get_fibonacci_last_digit_naive(int n)
{
    if (n <= 1)
        return n;

    int previous = 0;
    int current = 1;

    for (int i = 0; i < n - 1; ++i)
    {
        int tmp_previous = previous;
        previous = current;
        current = tmp_previous + current;
    }

    return current % 10;
}
unsigned long long int fibonacci_last_digit(int n)
{
    if (n <= 1)
    {
        return n;
    }
    else
    {
       unsigned long long int a[n];
        a[0] = 0;
        a[1] = 1;
        int i;
        for (i = 2; i <= n; i++)
        {
            a[i] = a[i - 1] + a[i - 2];
            a[i]=a[i]%10;
            //if(a[i]<0)a[i]=-a[i];
        }
        //cout<<a[n]<<'\n';
        
        return a[n];
    }
}
int main()
{
    int n;
    std::cin >> n;
    long c = fibonacci_last_digit(n);
    std::cout << c << '\n';
}




