class Solution {
public:
    int maxDistinctElements(vector<int>& nums, int k) {
    int n = nums.size();
    set<int>s;
    sort(nums.begin(),nums.end());
    for(int i=0;i<n;i++)
    {
        if(s.find(nums[i]-k)==s.end())
        {
            s.insert(nums[i]-k);
        }
        else
        {
            int last_val = *s.rbegin();
            if(last_val+1<=nums[i]+k)
            {
                s.insert(last_val+1);
            }
        }
    }

    return s.size();


    }
};