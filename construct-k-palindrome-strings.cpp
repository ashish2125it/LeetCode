class Solution {
public:
    bool canConstruct(string s, int k) {
    int n = s.length();
    if(k==n) return 1;
    if(k>n) return false;

    map<char,int>mp;
    for(int i=0;i<n;i++) mp[s[i]]++;

    int odd= 0,even = 0;

    for(auto it:mp)
    {
        int f = it.second;
        if(f%2==0) even++;
        else
        {
            if(f>1) 
            {
                even++;
                odd++;
            }
            else
            odd++;
        }
    }
   
    if(odd<=k) return 1;
   
   
 
    return 0;
 
  // odd - l,e,t,c,o,d



    }
};