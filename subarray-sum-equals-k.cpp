class Solution:
    def subarraySum(self, nums: List[int], k: int) -> int:
        ans = 0
        sum =0 
        desc = {}
        desc[0] = 1
        n = len(nums)
        for i in range(0,n):
            sum += nums[i]
            if((k-sum) in desc):
                ans = ans + desc[k-sum]
            elif ((sum-k) in desc):
                ans =ans + desc[sum-k]    

            if(sum in desc):
                desc[sum] = desc[sum] + 1
            else:
                desc[sum] = 1
        return ans            

        