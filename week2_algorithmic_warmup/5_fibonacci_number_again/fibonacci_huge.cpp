#include <iostream>
//#include <bits/stdc++.h>
using namespace std;
long long pisano(long long m){
long prev,curr,res;
prev=0;curr=1;
res=0;
for(long long i=0;i<m*m;i++){
    long temp=curr;
    curr=(prev+curr)%m;
    prev=temp;
if(prev==0 && curr==1){
    res=i+1;
}
}

return res;
}
/*long long get_fibonacci_huge_naive(long long n, unsigned long long int m)
{
    if (n <= 1)
        return n;

    unsigned long long int previous = 0;
    unsigned long long int current = 1;

    for (long long i = 0; i < n - 1; ++i)
    {
        unsigned long long int tmp_previous = previous;
        previous = current;
        current = tmp_previous + current;
    }

    return current % m;
}
*/
 unsigned long long int fibonacci_last_digit(unsigned long long int n, unsigned long long int m)
{
    long pisanoPeriod = pisano(m);
     
    n = n % pisanoPeriod;
     
    long prev = 0;
    long curr = 1;
     
    if (n == 0) 
        return 0;
    else if (n == 1)
        return 1;
     
    for(int i = 0; i < n - 1; i++)
    {
        long temp = 0;
        temp = curr;
        curr = (prev + curr) % m;
        prev = temp;
    }
    return curr % m;
}

int main()
{
    unsigned long long int n, m;
    std::cin >> n >> m;
    std::cout << fibonacci_last_digit(n, m) << '\n';
}
