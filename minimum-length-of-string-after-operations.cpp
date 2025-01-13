class Solution {
public:
    int minimumLength(string s) {
    int ans=0;
    int n = s.length();
    map<char,int>mp;
    for(int i=0;i<n;i++) mp[s[i]]++;
    for(int i=0;i<n;i++)
    {
        if(mp[s[i]]>=3)
        {
            while(mp[s[i]]>=3)
            {
                ans+=2;
                mp[s[i]]-=2;
            }
        }
    }
    return n-ans;

    }
};