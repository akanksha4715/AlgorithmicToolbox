#include <iostream>
using namespace std;
#include<bits/stdc++.h>
// Merges two subarrays of arr[].
// First subarray is arr[l..m]
// Second subarray is arr[m+1..r]


// UTILITY FUNCTIONS
// Function to print an array

int countInRange(int nums[], int num, int lo, int hi)
{
    int count = 0;
    for (int i = lo; i < hi; i++)
    {
        if (nums[i] == num)
        {
            count++;
        }
    }
    return count;
}
// Driver code
int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (size_t i = 0; i < n; ++i)
    {
        std::cin >> arr[i];
    }
    int arr_size = n;
    int mid = n / 2;

    sort(arr, arr+arr_size);
    mid = arr[mid];
    int count = countInRange(arr, mid, 0, n);
    if (count > n / 2)
        cout << 1;
    else
        cout << 0;
    return 0;
}