class Solution {
public:
    int countSetBits(int num) {
    int count = 0;
    
    while (num) {
        // Increment count if the least significant bit is set
        count += num & 1;
        
        // Right shift the number to check the next bit
        num >>= 1;
    }
    
    return count;
}
    bool canSortArray(vector<int>& nums) {
    int n = nums.size();
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n-1;j++)
        {
        if(nums[j] > nums[j+1] && countSetBits(nums[j]) == countSetBits(nums[j+1]))
        {
            swap(nums[j],nums[j+1]);
        }
        }
    }
        for(int i=0;i<n-1;i++)
        {
            if(nums[i] > nums[i+1]) return false;
        }
        return true;
            
    }
};