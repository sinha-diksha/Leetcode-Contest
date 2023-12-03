vector<string> twoEditWords(vector<string> &queries, vector<string> &dictionary)
{
  vector<string> ans;
  for (int i = 0; i < queries.size(); i++)
  {
    string r = queries[i];
    for (int j = 0; j < dictionary.size(); j++)
    {
      int sum = 0;
      for (int k = 0; k < r.length(); k++)
      {
        if (r[k] != dictionary[j][k])
        {
          sum++;
          if (sum > 2)
          {
            break;
          }
        }
      }
      if (sum <= 2)
      {
        ans.push_back(queries[i]);
        break;
      }
    }
  }
  return ans;
}