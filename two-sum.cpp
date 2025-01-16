class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        l = []  # define a list for answer 
        n = len(nums)  # len function 
        for i in range(0,n):
            for j in range(i+1,n):
                if(nums[i]+nums[j]==target):
                    l.append(i)
                    l.append(j)
                    break
        return l    
