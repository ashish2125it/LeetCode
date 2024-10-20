class Solution {
public:
    int numberOfSubstrings(string s, int k) {
    int  n = s.length();
    int ans= ((n+1)*n )/2;
    
    unordered_map<char,int>mp;
    int i=0;
    for(int j=0;j<n;j++)
    {
       mp[s[j]]++;

       while(mp[s[j]]>=k)
       {
          mp[s[i++]]--;
       }

       ans -= (j-i+1);
    }

    return ans;

    }
};