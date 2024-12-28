#define ll long long
class Solution {
public:
    long long continuousSubarrays(vector<int>& nums) {
        ll n = nums.size();
        ll ans = 0;

        // Map to store frequency of elements
        std::map<int, int> mp;
        int i = 0, j = 0;

        while (j < n) {
            mp[nums[j]]++;

            // Extract the minimum and maximum keys in the map
            int maxi = mp.rbegin()->first;
            int mini = mp.begin()->first;

            // If the difference exceeds 2, adjust the window
            while (maxi - mini > 2) {
                mp[nums[i]]--;
                if (mp[nums[i]] == 0) {
                    mp.erase(nums[i]);
                }
                i++;
                if (!mp.empty()) {
                    maxi = mp.rbegin()->first;
                    mini = mp.begin()->first;
                }
            }

            // Calculate subarrays count
            ans += (j - i + 1);
            j++;
        }

        return ans;
    }
};
