class Solution {
public:

bool solve(int dist,vector<int>&pos,int ball)
{
    int cnt= 1 ;
    int  p = pos[0];
    for(int i=1;i<pos.size();i++)
    {
        if(pos[i]-p>=dist)
        {
            cnt++;
            p = pos[i];
        }
    }

    return cnt>=ball;
}
    int maxDistance(vector<int>& pos, int m) {
    
    int n = pos.size();
    int low= 1,high = 0;
    int maxi= 0, mini = 1e9;
    sort(pos.begin(),pos.end());
    for(auto it:pos)
    {
        maxi = max(maxi,it);
        mini = min(mini,it);
    }

    high = maxi-mini;

    int ans= 0;
    while(low<=high)
    {
        int mid= (low+high)/2;

        if(solve(mid,pos,m))
        {
            ans = mid;
            low = mid +1;
        }
        else
        {
            high = mid-1;
        }

    }

    return ans;
    }
};