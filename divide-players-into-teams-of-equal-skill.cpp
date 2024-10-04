class Solution {
public:
    long long dividePlayers(vector<int>& s) {
    long long ans = 0;
    int n = s.size();
    sort(s.begin(),s.end());
    int i=0,j= s.size()-1;
    int t = s[0] + s[n-1];
    while(i<j)
    {
        if(s[i]+s[j]!=t) return -1;
        i++;
        j--;
    }

    i=0,j=n-1;
    while(i<j)
    {
        ans += (s[i]*s[j]);
        i++;
        j--;
    }
    return ans;
    }
};