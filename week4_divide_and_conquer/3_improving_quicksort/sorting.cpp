#include <iostream>
#include <vector>
#include <cstdlib>
#include <tuple>
using std::swap;
using std::vector;
using namespace std;
tuple<long, long> partition2(vector<long> &a, long l, long r)
{
  long x = a[l];
  long j = l;
  long j2 = l;
  for (long i = l + 1; i <= r; i++)
  {
    if (a[i] == x)
    {
      j2++;
      swap(a[i], a[j2]);
    }
    if (a[i] < x)
    {

      j++;
      j2++;
      swap(a[i], a[j]);
    }
  }
  swap(a[l], a[j]);
  //swap(a[j + 1], a[j2]);
  return make_tuple(j, j2);
}

void randomized_quick_sort(vector<long> &a, long l, long r)
{
  if (l >= r)
  {
    return;
  }

  long k = l + rand() % (r - l + 1);
  swap(a[l], a[k]);
  long m1, m2;
  tie(m1, m2) = partition2(a, l, r);

  randomized_quick_sort(a, l, m1 - 1);
  randomized_quick_sort(a, m2 + 1, r);
}

int main()
{
  long n;
  std::cin >> n;
  vector<long> a(n);
  for (size_t i = 0; i < a.size(); ++i)
  {
    std::cin >> a[i];
  }
  randomized_quick_sort(a, 0, a.size() - 1);
  for (size_t i = 0; i < a.size(); ++i)
  {
    std::cout << a[i] << ' ';
  }
}
