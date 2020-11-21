#include <iostream>

int get_change(int m)
{
  int count = 0;
  while (m != 0)
  {
    if (m >= 10)
    {
      m = m - 10;
      count++;
    }
    else if (m >= 5)
    {
      m = m - 5;
      count++;
    }
    else if (m >= 1)
    {
      m = m - 1;
      count++;
    }
  }

  //write your code here
  return count;
}

int main()
{
  int m;
  std::cin >> m;
  std::cout << get_change(m) << '\n';
}
