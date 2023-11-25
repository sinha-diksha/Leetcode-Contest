/*
2404. Most Frequent Even Element

Difficulty:Easy

Given an integer array nums, return the most frequent even element.

If there is a tie, return the smallest one. If there is no such element, return -1.



Example 1:

Input: nums = [0,1,2,2,4,4,1]
Output: 2
Explanation:
The even elements are 0, 2, and 4. Of these, 2 and 4 appear the most.
We return the smallest one, which is 2.
Example 2:

Input: nums = [4,4,4,9,2,4]
Output: 4
Explanation: 4 is the even element appears the most.
Example 3:

Input: nums = [29,47,21,41,13,37,25,7]
Output: -1
Explanation: There is no even element.


Constraints:

1 <= nums.length <= 2000
0 <= nums[i] <= 105*/

#include <bits/stdc++.h>
using namespace std;

int mostFrequentEven(vector<int> &nums)
{
  unordered_map<int, int> mp;
  int n = nums.size();
  for (int i = 0; i < nums.size(); i++)
  {
    if (nums[i] % 2 == 0)
    {
      mp[nums[i]]++;
    }
  }
  map<int, vector<int>, greater<int>> mp1;
  unordered_map<int, int>::iterator it = mp.begin();
  while (it != mp.end())
  {
    mp1[it->second].push_back(it->first);
    it++;
  }
  if (mp1.size() == 0)
  {
    return -1;
  }
  map<int, vector<int>, greater<int>>::iterator it1 = mp1.begin();
  sort(it1->second.begin(), it1->second.end());
  return it1->second[0];
}

int main()
{
  int t;
  cin >> t;
  while (t--)
  {
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++)
    {
      cin >> nums[i];
    }
    cout << mostFrequentEven(nums) << endl;
  }
}