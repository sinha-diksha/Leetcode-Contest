/*Optimal Partition of String

Difficulty:Medium
Given a string s, partition the string into one or more substrings such that the characters in each substring are unique. That is, no letter appears in a single substring more than once.

Return the minimum number of substrings in such a partition.

Note that each character should belong to exactly one substring in a partition.



Example 1:

Input: s = "abacaba"
Output: 4
Explanation:
Two possible partitions are ("a","ba","cab","a") and ("ab","a","ca","ba").
It can be shown that 4 is the minimum number of substrings needed.
Example 2:

Input: s = "ssssss"
Output: 6
Explanation:
The only valid partition is ("s","s","s","s","s","s").


Constraints:

1 <= s.length <= 105
s consists of only English lowercase letters.*/

#include <bits/stdc++.h>
using namespace std;

int partitionString(string s)
{
  int n = s.length();
  int ans = 0;
  int target = 0;
  unordered_map<char, bool> mp;

  int e = 0;
  while (e < n)
  {
    if (mp.count(s[e]) > 0)
    {
      target++;
      mp.clear();
      mp[s[e]] = true;
    }
    else
    {
      mp[s[e]] = true;
    }
    e++;
    if (e == n)
    {
      target++;
    }
  }
  return target;
}

int main()
{
  int t;
  cin >> t;
  while (t--)
  {
    string s;
    cin >> s;
    cout << partitionString(s) << endl;
  }
}