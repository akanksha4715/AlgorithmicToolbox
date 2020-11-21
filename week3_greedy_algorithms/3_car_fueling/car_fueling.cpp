#include <iostream>
#include <vector>
using namespace std;
using std::cin;
using std::cout;
using std::max;
using std::vector;

int compute_min_refills(int dist, int tank, vector<int> &stops)
{
    stops.insert(stops.begin(), 0);
    stops.insert(stops.end(), dist);
    int numRefill = 0, currentRefill = 0, n = stops.size(), lastRefill;
    //cout << n << endl;
    while (currentRefill <= n)
    {
        lastRefill = currentRefill;
        while (currentRefill <= n && (stops[currentRefill + 1] - stops[lastRefill]) <= tank)
        {
            currentRefill += 1;
        }
        if (currentRefill == lastRefill)
            return -1;
        if (currentRefill <= n)
            numRefill += 1;
    }
    // write your code here
    return numRefill;
}

int main()
{
    int d = 0;
    cin >> d;
    int m = 0;
    cin >> m;
    int n = 0;
    cin >> n;

    vector<int> stops(n);
    for (size_t i = 0; i < n; ++i)
        cin >> stops.at(i);

    cout << compute_min_refills(d, m, stops) << "\n";

    return 0;
}
