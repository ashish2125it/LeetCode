class Solution {
public:
    int minTaps(int n, vector<int>& ranges) {
    vector<int>arr(n+1,0);
    for(int i=0;i<ranges.size();i++)
    {
        if(ranges[i]==0) continue;
        int left = max(0,i-ranges[i]);
        int right = i + ranges[i];
        arr[left] =  max(arr[left],right);
    }
    
    int ans= 0 ,end = 0,dist_point= 0 ;

    for(int i=0;i<=n && end<n;end = dist_point)
    {
        ans++;
        while(i<arr.size() && i<=end)
        dist_point = max(dist_point,arr[i++]);

        if(dist_point==end) return -1;
    }
    return ans;
    }
};