#include <algorithm>
#include <sstream>
#include <iostream>
#include <vector>
#include <string>
using namespace std;
using std::string;
using std::vector;
bool check(string a, string b)
{
  string c, d;
  if (a.at(0) == b.at(0))
  {
    c = a + b;
    d = b + a;

    return stoi(c)>stoi(d);
  }
  else
  {
    return (a.at(0) > b.at(0));
  }
}
string largest_number(vector<string> a)
{
  //write your code here
  sort(a.begin(), a.end(), check);
  std::stringstream ret;
  for (size_t i = 0; i < a.size(); i++)
  {
    ret << a[i];
  }
  string result;
  ret >> result;
  return result;
}

int main()
{
  int n;
  std::cin >> n;
  vector<string> a(n);
  for (size_t i = 0; i < a.size(); i++)
  {
    std::cin >> a[i];
  }
  std::cout << largest_number(a);
}
