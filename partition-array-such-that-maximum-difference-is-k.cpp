class Solution {
public:
    int partitionArray(vector<int>& nums, int k) {
    int n = nums.size();
    sort(nums.begin(),nums.end());
    int cnt=0;
    int i=0,j=0;
    while(i<n)
    {
        j = i;
        bool check = false;
        while(i<n && nums[i]-nums[j]<=k)
        {
            i++;
            check = true;
        }
        if(check==false) i++;
        
        cnt++;
    }
    return cnt;
    }
};