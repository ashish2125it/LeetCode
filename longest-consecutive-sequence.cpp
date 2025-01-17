class Solution:
    def longestConsecutive(self, nums: List[int]) -> int:
        n = len(nums)
        nums.sort()
        ans = 0

        for i in range(0,n):
            j = i
            cnt = 1
            while(j+1<n and nums[j]+1==nums[j+1]):
                j = j+1
                cnt = cnt +1

            if(cnt>ans):
                ans = cnt
            i = j+1
        return ans             

                


        