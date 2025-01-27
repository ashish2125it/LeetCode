class Solution {
public:
    void nextPermutation(vector<int>& nums) {
    int p = 0;
    int n = nums.size();
    for(int i=n-2;i>=0;i--)
    {
        if(nums[i]<nums[i+1])
        {
            p = i;
            break;
        }
    }
    
    int mini = INT_MAX;
    int index = -1;
   
    for(int i=p+1;i<n;i++)
    {
         if(nums[i]>nums[p])
         {
            if(mini > nums[i])
            {
                mini = nums[i];
                index = i;
            }

         }
    }
    if(index!=-1)
    {
         swap(nums[p],nums[index]);
    }
    else
    {
    reverse(nums.begin(),nums.end());
    return ;
    }

    sort(nums.begin()+p+1,nums.end());

    }
};