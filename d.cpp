/*You are given a string s consisting of lowercase letters and an integer k. We call a string t ideal if the following conditions are satisfied:

t is a subsequence of the string s.
The absolute difference in the alphabet order of every two adjacent letters in t is less than or equal to k.
Return the length of the longest ideal string.

A subsequence is a string that can be derived from another string by deleting some or no characters without changing the order of the remaining characters.

Note that the alphabet order is not cyclic. For example, the absolute difference in the alphabet order of 'a' and 'z' is 25, not 1.



Example 1:

Input: s = "acfgbd", k = 2
Output: 4
Explanation: The longest ideal string is "acbd". The length of this string is 4, so 4 is returned.
Note that "acfgbd" is not ideal because 'c' and 'f' have a difference of 3 in alphabet order.
Example 2:

Input: s = "abcd", k = 3
Output: 4
Explanation: The longest ideal string is "abcd". The length of this string is 4, so 4 is returned.


Constraints:

1 <= s.length <= 105
0 <= k <= 25
s consists of lowercase English letters.*/

#include <bits/stdc++.h>
using namespace std;

int longestIdealString(string s, int k)
{
  int n = s.length();
  vector<int> v(26, 0);
  int maxi = 1;
  for (int i = 0; i < n; i++)
  {
    int ans = 1;
    int l = max(0, (s[i] - 'a') - k);
    int h = min(25, (s[i] - 'a') + k);
    for (int j = l; j <= h; j++)
    {
      ans = max(ans, v[j] + 1);
    }
    v[s[i] - 'a'] = ans;
    maxi = max(maxi, v[s[i] - 'a']);
  }
  return maxi;
}

int main()
{
  int t;
  cin >> t;
  while (t--)
  {
    string s;
    int k;
    cin >> s >> k;
    cout << longestIdealString(s, k) << endl;
  }
}