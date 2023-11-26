/*
DIVIDE INTERVALS INTO MINIMUM NUMBER OF GROUPS

You are given a 2D integer array intervals where intervals[i] = [lefti, righti] represents the inclusive interval [lefti, righti].

You have to divide the intervals into one or more groups such that each interval is in exactly one group, and no two intervals that are in the same group intersect each other.

Return the minimum number of groups you need to make.

Two intervals intersect if there is at least one common number between them. For example, the intervals [1, 5] and [5, 8] intersect.



Example 1:

Input: intervals = [[5,10],[6,8],[1,5],[2,3],[1,10]]
Output: 3
Explanation: We can divide the intervals into the following groups:
- Group 1: [1, 5], [6, 8].
- Group 2: [2, 3], [5, 10].
- Group 3: [1, 10].
It can be proven that it is not possible to divide the intervals into fewer than 3 groups.
Example 2:

Input: intervals = [[1,3],[5,6],[8,10],[11,13]]
Output: 1
Explanation: None of the intervals overlap, so we can put all of them in one group.


Constraints:

1 <= intervals.length <= 105
intervals[i].length == 2
1 <= lefti <= righti <= 106*/

#include <bits/stdc++.h>
using namespace std;

int minGroups(vector<vector<int>> &intervals)
{
  int n = intervals.size();
  vector<int> arrival;
  vector<int> depart;
  for (int i = 0; i < n; i++)
  {
    arrival.push_back(intervals[i][0]);
    depart.push_back(intervals[i][1]);
  }
  sort(arrival.begin(), arrival.end());
  sort(depart.begin(), depart.end());
  int maxCount = 0;
  int maxOverlap = 0;
  int i = 0;
  int j = 0;
  while (i < n && j < n)
  {
    if (arrival[i] <= depart[j])
    {
      maxCount++;
      i++;
    }
    else
    {
      maxCount--;
      j++;
    }
    maxOverlap = max(maxOverlap, maxCount);
  }
  return maxOverlap;
}

int main()
{
  int t;
  cin >> t;
  while (t--)
  {
    int n;
    cin >> n;
    vector<vector<int>> v;
    for (int i = 0; i < n; i++)
    {
      int x, y;
      cin >> x >> y;
      vector<int> v1;
      v1.push_back(x);
      v1.push_back(y);
      v.push_back(v1);
    }

    cout << minGroups(v) << endl;
  }
}