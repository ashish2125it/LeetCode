#define ll long long
class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        int n = arr.size();
        vector<int> dp(n, INT_MAX);  // Store min length of subarray ending at i
        int leftMin = INT_MAX, ans = INT_MAX;
        int sum = 0, left = 0;

       
        for (int right = 0; right < n; ++right) {
            sum += arr[right];

            while (sum > target) { 
                sum -= arr[left++];
            }

            if (sum == target) {
                int currLen = right - left + 1;
                if (left > 0 && dp[left - 1] != INT_MAX) {
                    ans = min(ans, currLen + dp[left - 1]); 
                }
                leftMin = min(leftMin, currLen);  
            }
            dp[right] = leftMin;  
        }

        return ans == INT_MAX ? -1 : ans;
    }
};
