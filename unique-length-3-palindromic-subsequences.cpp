class Solution {
public:
    int countPalindromicSubsequence(string s) {
    int n = s.length();
    // first and last char is fixed _?_
    // find the first and last same char and in between the unique char is the number of sub
    unordered_map<char,pair<int,int>>mp;
    for(char i='a';i<='z';i++)
    mp[i] = {-1,-1};

    for(int i=0;i<n;i++)
    {
        if(mp[s[i]].first==-1)
        mp[s[i]].first = i;
    }

    for(int i=n-1;i>=0;i--)
    {
        if(mp[s[i]].second==-1)
        mp[s[i]].second = i;
    }
  int ans= 0;
   for(auto it:mp)
   {
        int start = it.second.first;
        int end = it.second.second;
        unordered_set<char>st;
        for(int i=start+1;i<end;i++)
        {
           st.insert(s[i]);
        }
        ans += st.size();
   }
   return ans;
    }
};