#include <iostream>

long long lcm_naive(int a, int b)
{
  for (long l = 1; l <= (long long)a * b; ++l)
    if (l % a == 0 && l % b == 0)
      return l;

  return (long long)a * b;
}
long long gcd(long long a, long long b)
{
  long long num1, num2, rem;
  if (a > b)
  {
    num1 = a;
    num2 = b;
  }
  else
  {
    num1 = b;
    num2 = a;
  }
  while (num2 != 0)
  {
    rem = num1 % num2;
    num1 = num2;
    num2 = rem;
  }
  return num1;
}
int main()
{
  long long a, b;
  std::cin >> a >> b;
  std::cout << (long long)(a * b) / gcd(a, b) << std::endl;
  //std::cout << lcm_naive(a, b) << std::endl;
  return 0;
}
