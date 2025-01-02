class Solution {
public:
bool vowel(char x)
{
  if(x=='a' ||x=='i' || x=='e' || x=='u' || x=='o' ) 
  return 1;
  return 0;
}
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) 
    {
      int n =  queries.size();
      int l= words.size();
        vector<long long>precalculate(l+1,0);
        for(int i=0;i<l;i++)
        {
            char first = words[i][0];
            char last = words[i][words[i].size()-1];
            if(vowel(first) && vowel(last))
            {
              precalculate[i+1] = 1 + precalculate[i];
            }
            else
            precalculate[i+1] = precalculate[i];
        }

        vector<int>ans;
        for(int i=0;i<n;i++)
        {
          int right= queries[i][1];
          int left= queries[i][0] ;
         ans.push_back(precalculate[right+1]-precalculate[left]);
        }
        return ans;
    }
};