#include <cstdlib>
#include <iostream>
#include <vector>
#include <bits/stdc++.h>
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
    while (true)
    {
        srand((unsigned)time(0));
        int n = (rand() % 100000) + 1;
        //cout << n;
        vector<long long> a;
        for (size_t i = 0; i < n; i++)
        {

            a.push_back((rand() % 1000000000) + 1);
        }
        long long elem = get_majority_element(a, 0, a.size() - 1);
        sort(a.begin(), a.end());
        int mid = n / 2;
        mid = a[mid];
        bool res1, res2;
        res1 = get_count(a,elem,0,n) > (n / 2);
        res2 = get_count(a, mid, 0, n) > (n / 2);
        if (res1!=res2)
        {
            cout << "found prob" << endl;
            for (int i = 0; i < n; i++)
            {
                cout << a[i] << endl;
            }
            cout << "Results\n";
            cout << mid << endl;
            cout << elem << endl;
            break;
        }
        else
        {
            cout << "Okay" << endl;
        }
    }

    return 0;
}