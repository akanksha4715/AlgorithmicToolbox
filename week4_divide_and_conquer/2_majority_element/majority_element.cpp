#include <iostream>
#include <vector>
using namespace std;
long long get_count(vector<long long> &a, long long c, long long lo, long long hi)
{
  long long count = 0;
  for (size_t i = lo; i < hi; i++)
  {
    if (a[i] == c)
      count++;
  }
  return count;
}
long long get_majority_element(vector<long long> &a, long long lo, long long hi)
{
  long long mid;
  mid = lo + (hi - lo) / 2;
  if (lo == hi)
    return a[lo];
  long long left, right;
  left = get_majority_element(a, lo, mid);
  right = get_majority_element(a, mid + 1, hi);
  if (left == right)
  {
    return a[left];
  }
  else
  {
    long long lcount, rcount;

    lcount = get_count(a, left, lo, hi);
    rcount = get_count(a, right, lo, hi);
    return lcount > rcount ? left : right;
  }
}
int main()
{

  long long n;
  cin >> n;
  vector<long long> a;
  for (size_t i = 0; i < n; i++)
  {
    long long l;
    cin >> l;
    a.push_back(l);
  }
  long long elem = get_majority_element(a, 0, a.size() - 1);
  long long count = get_count(a, elem, 0, n);
  if (count > n / 2)
    cout << 1;
  else
    cout << 0;
  return 0;
}