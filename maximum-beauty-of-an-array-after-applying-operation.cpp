class Solution {
public:
    int maximumBeauty(vector<int>& nums, int k) {
        int n = nums.size();
        int maxi = 0;
        
        // Find the maximum value in the input array
        for(auto it : nums) {
            maxi = max(maxi, it);
        }

       
        map<int, int> m;

        // Mark the range in the map
        for(int i = 0; i < n; i++) {
            int left = nums[i] - k;
            int right = nums[i] + k;
            m[left]++;
            m[right + 1]--;  
        }

        
        int maxBeauty = 0;
        int currentBeauty = 0;
        
        for(auto& entry : m) {
            currentBeauty += entry.second;
            maxBeauty = max(maxBeauty, currentBeauty);
        }

        return maxBeauty;
    }
};
