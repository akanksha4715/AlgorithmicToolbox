#include <algorithm>
#include <iostream>
#include <climits>
#include <vector>
using namespace std;
using std::vector;
#include <bits/stdc++.h>
struct Segment
{
  int start, end;
};

vector<int> optimal_points(vector<Segment> &segments)
{
  Segment curSeg = segments[0];
  vector<int> points;
  //write your code here
  for (size_t i = 1; i < segments.size(); ++i)
  {
    if (curSeg.end >= segments[i].start)
    {
      curSeg.start = max(curSeg.start, segments[i].start);
      curSeg.end = min(curSeg.end, segments[i].end);
    }
    else
    {
      points.push_back(curSeg.start);
      curSeg = segments[i];
    }

    // points.push_back(segments[i].start);
    // points.push_back(segments[i].end);
  }
  points.push_back(curSeg.start);

  return points;
}
bool compareSegment(Segment seg1, Segment seg2)
{
  return (seg1.start < seg2.start);
}
int main()
{
  int n;
  std::cin >> n;
  vector<Segment> segments(n);
  for (size_t i = 0; i < segments.size(); ++i)
  {
    std::cin >> segments[i].start >> segments[i].end;
  }

  sort(segments.begin(), segments.end(), compareSegment);
  // for (int i = 0; i < segments.size(); i++)
  // {
  //   cout << segments[i].start << segments[i].end << endl;
  // }
  vector<int>
      points = optimal_points(segments);
  std::cout << points.size() << "\n";
  for (size_t i = 0; i < points.size(); ++i)
  {
    std::cout << points[i] << " ";
  }
}
