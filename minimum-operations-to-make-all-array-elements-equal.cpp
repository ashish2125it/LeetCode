class Solution {
public:
    vector<long long> minOperations(vector<int>& nums, vector<int>& q) {
        int n = nums.size(), m = q.size();
        vector<long long> ans(m);
        
       
        long long sum = 0;
        for (auto it : nums) sum += it;

       
        sort(nums.begin(), nums.end());
        
       
        vector<long long> prefix(n, 0);
        prefix[0] = nums[0];
        for (int i = 1; i < n; i++) prefix[i] = prefix[i - 1] + nums[i];

      
        int mini = nums[0], maxi = nums[n - 1];
        
        for (int i = 0; i < m; i++) {
            if (q[i] >= maxi) {
               
                ans[i] =  (long long)n * q[i] -sum;
            } 
            else if (q[i] <= mini) {
               
                ans[i] = abs(sum - (long long)n * q[i]);
            } 
            else {
               
                int low = 0, high = n - 1, index = n;
                while (low <= high) {
                    int mid = low + (high - low) / 2;
                    if (nums[mid] >= q[i]) {
                        index = mid;
                        high = mid - 1;
                    } else {
                        low = mid + 1;
                    }
                }
                
                
                long long left_sum = abs( (long long)q[i] * index - prefix[index - 1] );
                long long right_sum = abs((prefix[n - 1] - prefix[index - 1]) - (long long)q[i] * (n - index) );
                
                ans[i] = left_sum + right_sum;
                ans[i] = abs(ans[i]);
            }
        }

        return ans;
    }
};
