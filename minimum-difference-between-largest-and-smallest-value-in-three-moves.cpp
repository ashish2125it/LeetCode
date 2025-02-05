class Solution {
public:
    int minDifference(vector<int>& nums) {
        int n = nums.size();
        if (n <= 3) return 0; // If size is <= 3, we can remove all elements.

        sort(nums.begin(), nums.end()); // Sort the array
        
        // Try removing up to 3 smallest or 3 largest elements
        int ans = min({nums[n-1] - nums[3],   // Remove first 3 elements
                       nums[n-2] - nums[2],   // Remove 2 from start, 1 from end
                       nums[n-3] - nums[1],   // Remove 1 from start, 2 from end
                       nums[n-4] - nums[0]}); // Remove last 3 elements
        
        return ans;
    }
};
