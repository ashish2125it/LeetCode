class Solution {
public:
    bool solve(int len, vector<int>& nums, int n) {
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            cnt += max(0, nums[i] - len + 1);
        }
        return cnt >= 3;
    }

    int maximumLength(string s) {
        int n = s.length();
        vector<vector<int>> v(26); // Frequencies of contiguous segments for each character

        int i = 0;
        while (i < n) {
            int cnt = 1;
            while (i + 1 < n && s[i] == s[i + 1]) {
                i++;
                cnt++;
            }
            v[s[i] - 'a'].push_back(cnt);
            i++;
        }

        int ans = -1;
        for (int i = 0; i < 26; i++) {
            vector<int> temp = v[i];
            if (temp.empty()) continue; // Skip empty vectors
            sort(temp.begin(), temp.end());
            int low = 1, high = temp.back(); // Use the largest segment length as the upper bound
            while (low <= high) {
                int mid = (low + high) / 2;
                if (solve(mid, temp, temp.size())) {
                    ans = max(ans, mid);
                    low = mid + 1;
                } else {
                    high = mid - 1;
                }
            }
        }
        return ans;
    }
};
