class Solution {
public:
    bool isPossibleToRearrange(string s, string t, int k) {
    int len = s.length()/k;
    unordered_map<string,int>mp;
    int n = s.length();
    string ans= "";
    int cnt= 0,i=0;
    while(i<n)
    {
         ans+=s[i];
         cnt++;
         if(cnt==len)
         {
            cnt  =0 ;
            mp[ans]++;
            ans = "";
         }
         i++;
    }

    i=0,cnt=0;
    ans=  "";
    while(i<n)
    {
        ans += t[i];
        cnt++;
        if(cnt==len)
        {
            if(mp.find(ans)==mp.end()) return 0;

            mp[ans]--;
            if(mp[ans]==0) mp.erase(ans);

            cnt= 0;
            ans ="";
        }
        i++;
    }
    return 1;

    }
};