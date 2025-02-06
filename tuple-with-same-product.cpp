class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        map<long long, int> mp;

        
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) { 
                mp[1LL * nums[i] * nums[j]]++;
            }
        }

        
        for (auto& [product, count] : mp) {
            if (count > 1) {
                ans += (count * (count - 1)) / 2 * 8; 
            }
        }

        return ans;
    }
};
