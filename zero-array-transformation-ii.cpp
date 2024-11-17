class Solution {
public:
    bool check(int k, vector<int>& nums, vector<vector<int>>& q) {
        vector<int> temp(nums.size()+1, 0);

       
        for (int i = 0; i < k; i++) {
            int left = q[i][0];
            int right = q[i][1];
            int val = q[i][2];
            temp[left] += val;
            if (right + 1 < nums.size())
                temp[right + 1] -= val;
        }

       
        for (int i = 1; i <= nums.size(); i++) {
            temp[i] += temp[i - 1];
        }

       
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] > temp[i]) return false;
        }

        return true;
    }

    int minZeroArray(vector<int>& nums, vector<vector<int>>& q) {
        int n = nums.size();
        int m = q.size();
        int ans = -1;
        int low = 0, high = m ; 
        while (low <= high) {
            int mid = (low + high) / 2;

            if (check(mid, nums, q)) {
                ans = mid;
                high = mid - 1;  
            } else {
                low = mid + 1;
            }
        }

        return ans;
    }
};
