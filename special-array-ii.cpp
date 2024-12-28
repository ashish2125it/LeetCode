class Solution {
public:
    vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& qu) {
        int n = nums.size();
        vector<bool>ans;
        vector<int>temp1(n,0);
        vector<int>temp(n,0);
        for(int i=1;i<n;i++)
        {
            if(nums[i]%2==0 && nums[i-1]%2==0 || (nums[i]%2!=0 && nums[i-1]%2!=0))
            {
                temp1[i] = 1;
            }
            else
            temp1[i] = 0 ;
        }

    //    for(auto it:temp)
    //     cout<<it<<" ";
           temp[0] = temp1[0];

        for(int i=1;i<n;i++)
        temp[i] = temp[i-1]  + temp1[i]  ;

        for(auto it:temp)
        cout<<it<<" ";

        for(auto q:qu)
        {
            int left = q[0];
            int right = q[1];
            if(left==right)
            {
                ans.push_back(true);
                continue;
            }
            int s =0;
            if(left-1>=0)
            s = temp[right] - temp[left-1];
            else
            s = temp[right];

            if(s==0)
            ans.push_back(true);
            else
            {
                if(s>1)
                {
                    ans.push_back(false);
                    continue;
                }
                if(s==1)
                {
                    if(temp1[left]==1)
                    ans.push_back(true);
                    else
                    ans.push_back(false);
                }
                
            }
        }
        return ans;

    }
};