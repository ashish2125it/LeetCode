class Solution {
public:
    int maxDifference(string s) {
     int n = s.length();
     map<char,int>mp;
        for(auto it:s)
            mp[it]++;
        int maxi = -1e9,mini = 1e9;
        for(auto it:mp)
            {
                int f = it.second;
                if(f%2==0)
                     mini = min(mini,f);
                else
                    maxi = max(maxi,f);
            }
        return maxi- mini;
    }
};