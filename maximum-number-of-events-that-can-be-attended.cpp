class Solution {
public:
static bool cmp(vector<int>&a,vector<int>&b)
{
     if(a[1] < b[1]) return 1;
     if(a[1]==b[1]) return a[0]<b[0];
     return false;
}
    int maxEvents(vector<vector<int>>& ev) {
    int n = ev.size();
    sort(ev.begin(),ev.end(),cmp);
    int cnt= 0;
    set<int>days;
    for(int i=1;i<=1e5;i++) days.insert(i);

    for(int i=0;i<n;i++)
    {
        int start = ev[i][0] ;
        int end = ev[i][1];
        auto it = days.lower_bound(start);
        if(it==days.end() || *it>end) continue;

        cnt++;
        days.erase(it);
    }
    return cnt;

    

    }
};