class Solution {
public:
    int maxLength(vector<int>& arr) {
        int n = arr.size();
        int ans = 1;
        const long long LIMIT = 1e18; // Define a safe limit for the product

        for (int i = 0; i < n; i++) {
            int currentHCF = arr[i];
            long long pro = arr[i]; // Initialize the product with the first element
            long long currentLCM = arr[i];

            for (int j = i; j < n; j++) {
                if (j > i) {
                    // Update HCF for the current subarray
                    currentHCF = gcd(currentHCF, arr[j]);

                    // Update LCM and check overflow
                    long long gcdValue = gcd(currentLCM, arr[j]);
                    if (currentLCM > LIMIT / arr[j] * gcdValue) break; // Prevent overflow
                    currentLCM = (currentLCM / gcdValue) * arr[j];

                    // Update product and check overflow
                    if (pro > LIMIT / arr[j]) break; // Prevent overflow
                    pro *= arr[j];
                }

                // Check if product equals HCF * LCM
                if (pro == 1LL * currentHCF * currentLCM) {
                    ans = max(ans, j - i + 1);
                }
            }
        }

        return ans;
    }
};
