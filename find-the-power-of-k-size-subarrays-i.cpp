class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int k) {
    int n = nums.size();
    vector<pair<int,int>>temp(n);
    temp[0].first = 1;        // number of greater
    temp[0].second = nums[0]; // last greater
    
    vector<int> ans;
    for(int i=1;i<n;i++)
    {
        if(nums[i] == temp[i-1].second+1)
        {
            temp[i].first = 1 + temp[i-1].first ;
            temp[i].second = nums[i];
        }
        else
        {
            temp[i].first = 1;
            temp[i].second = nums[i];
        }
    }

    for(int i=k-1;i<n;i++)
    {
        if(temp[i].first>=k)
        ans.push_back(temp[i].second);
        else
        ans.push_back(-1);
        
    }

    return ans;
    }
};