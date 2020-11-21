#include <iostream>
#include <vector>
using namespace std;
using std::vector;
#include <bits/stdc++.h>
void swap(int *xp, int *yp)
{
  int temp = *xp;
  *xp = *yp;
  *yp = temp;
}
void swap1(double *xp, double *yp)
{
  double temp = *xp;
  *xp = *yp;
  *yp = temp;
}

// A function to implement bubble sort
void bubbleSort(vector<int> &arr, int n, vector<double> vpw, vector<int> &arr1)
{
  int i, j;
  for (i = 0; i < n - 1; i++)

    // Last i elements are already in place
    for (j = 0; j < n - i - 1; j++)
      if (vpw[j] < vpw[j + 1])
      {
        swap(&arr[j], &arr[j + 1]);
        swap(&arr1[j], &arr1[j + 1]);
        swap1(&vpw[j], &vpw[j + 1]);
      }
}
double get_optimal_value(int capacity, vector<int> weights, vector<int> values)
{
  double value = 0.0;
  int index = 0;
  //cout << weights.size();
  while (capacity != 0 && index < weights.size())
  {
    //cout << capacity << endl;
    if (weights[index] <= capacity)
    {
      value += double(values[index]);
      capacity = capacity - weights[index];
      index++;
    }
    else
    {
      // int fac = weights[index] - capacity;
      value += ((values[index] * capacity) / double(weights[index]));
      break;
    }
  }

  // write your code here

  return value;
}

int main()
{
  int n;
  int capacity;
  std::cin >> n >> capacity;
  vector<int> values(n);
  vector<int> weights(n);
  vector<double> vpw(n);
  for (int i = 0; i < n; i++)
  {
    cin >> values[i] >> weights[i];
    //cout << i;
    vpw[i] = double(values[i]) / double(weights[i]);
    //cout << vpw[i] << endl;
  }

  bubbleSort(values, n, vpw, weights);
  //cout << "values sorted" << endl;
  //bubbleSort(weights, n, vpw);
  // for (int i = 0; i < n; i++)
  // {
  //   cout << values[i] << " " << weights[i] << endl;
  // }
  double optimal_value = get_optimal_value(capacity, weights, values);

  std::cout<<fixed<<setprecision(4)<< optimal_value << std::endl;
  //std::cout << optimal_value << std::endl;
  return 0;
}
