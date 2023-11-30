class Solution
{
public:
  int longestSubarray(vector<int> &nums)
  {
    int a = *max_element(nums.begin(), nums.end());
    int maxLen = 0;
    int s = -1;
    int e = -1;
    for (int i = 0; i < nums.size(); i++)
    {
      if (nums[i] == a)
      {
        if (s == -1)
        {
          s = i;
          e = i;
        }
        else
        {
          e = i;
        }
        maxLen = max(maxLen, e - s + 1);
      }
      else
      {
        s = -1;
        e = -1;
      }
    }

    return maxLen;
  }
};