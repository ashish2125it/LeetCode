class Solution {
public:
int solve(int i,vector<int>&nums,int prev1,int prev2,int n)
{
    if(i>=n) return 0;


    int take = 0 ;
    if(nums[i]==prev1+prev2 && prev1!=-1 && prev2!=-1)
    {
        take = 1 + solve(i+1,nums,nums[i],prev1,n);
    }
    else
    {
        if(prev1==-1 && prev2==-1)
        {
            take = 1 + solve(i+1,nums,nums[i],prev2,n);
        }
        else if(prev2==-1)
        {
            take = 1 + solve(i+1,nums,prev1,nums[i],n);
        }
    } 

   int not_take = solve(i+1,nums,prev1,prev2,n);

    return max(not_take,take);
}
    int lenLongestFibSubseq(vector<int>& arr) {
    int n = arr.size();
    
    return solve(0,arr,-1,-1,n);
    }
};