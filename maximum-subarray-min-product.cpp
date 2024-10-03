#define ll long long
class Solution {
vector<int> solve2(vector<int>&nums, int n) {
    stack<int>s;
    vector<int>ans(n,n);
    for(int i=n-1;i>=0;i--) {
        while(!s.empty() && nums[s.top()] >= nums[i])
            s.pop();

        if(s.size() > 0)
            ans[i] = s.top();

        s.push(i);
    }
    return ans;
}

vector<int> solve1(vector<int>&nums, int n) {
    stack<int>s;
    vector<int>ans(n,-1);
    for(int i=0;i<n;i++) {
        while(!s.empty() && nums[s.top()] >= nums[i])
            s.pop();

        if(s.size() > 0)
            ans[i] = s.top();

        s.push(i);
    }
    return ans;
}

public:
    int maxSumMinProduct(vector<int>& nums) {
        int n = nums.size();
        vector<long long int> prefix_sum(n, 0);  // Correct initialization size
        
        // Correct prefix sum calculation
        prefix_sum[0] = nums[0];
        for(int i = 1; i < n; i++) {
            prefix_sum[i] = nums[i] + prefix_sum[i - 1]; // Fixed to avoid double accumulation
        }
        
        vector<int> prev_max_index = solve1(nums, n);
        vector<int> next_max_index = solve2(nums, n);

        long long int ans = 0;
        int mod = 1e9 + 7;

        for(int i = 0; i < n; i++) {
            long long int u = 0;
            
            // Correct range sum calculation
            if (prev_max_index[i] != -1) {
                u = nums[i] * (prefix_sum[next_max_index[i] - 1] - prefix_sum[prev_max_index[i]]);
            } else {
                u = nums[i] * prefix_sum[next_max_index[i] - 1];
            }

            ans = max(ans, u);
        }

        return ans % mod;
    }
};
