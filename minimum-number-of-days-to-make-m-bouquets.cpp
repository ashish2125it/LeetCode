#define ll long long int
class Solution {
public:
    bool solve(int days, vector<int>& b, int m, int k) {
        int len = 0;

        for (int i = 0; i < b.size(); i++) {
            if (b[i] <= days) {
                len++;
                if (len == k) {
                    m--;
                    len = 0; // Reset length after forming a bouquet
                    if (m == 0) return true; // Early return if all bouquets are formed
                }
            } else {
                len = 0; // Reset if current flower can't be picked
            }
        }
        return false;
    }

    int minDays(vector<int>& b, int m, int k) {
        int n = b.size();
        ll x = 1LL * m * k; // Corrected to avoid overflow
        if (x > n) return -1;

        int low = *min_element(b.begin(), b.end());
        int high = *max_element(b.begin(), b.end());

        int ans = -1;
        while (low <= high) {
            int mid = low + (high - low) / 2; // Avoids overflow
            if (solve(mid, b, m, k)) {
                ans = mid;
                high = mid - 1; // Search for a smaller valid day
            } else {
                low = mid + 1; // Increase days to meet bouquet requirement
            }
        }
        return ans;
    }
};
