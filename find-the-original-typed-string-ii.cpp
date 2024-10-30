int dp[2005][2005];
const int MOD = 1e9 + 7;  // Defining the mod constant
int prefix[2005][2005];

class Solution {
public:
    int possibleStringCount(string p, int k) {
        vector<int> b;
        int n = p.size();
        int c = 0;

        // Calculate frequency of consecutive identical characters
        for (int i = 1; i < n; i++) {
            if (p[i] == p[i - 1]) {
                c++;
            } else {
                b.push_back(c + 1);
                c = 0;
            }
        }
        b.push_back(c + 1);  // Adding last block

        int d = 1;
        // Calculate the product of all blocks (modular arithmetic applied here)
        for (int i = 0; i < b.size(); i++) {
            d = (1LL * d * b[i]) % MOD;  // Use 1LL to prevent overflow
        }

        int w = b.size();
        int z = 0;

        if (w >= k) {
            // No need for further computation, return the product directly
            return d;
        } else {
            dp[0][0] = 1;
            prefix[0][0] = 1;

            // Build the prefix sum array with modular arithmetic
            for (int j = 1; j <= k - 1; j++) {
                prefix[0][j] = (dp[0][j] + prefix[0][j - 1]) % MOD;
            }

            // Dynamic programming to calculate the number of ways
            for (int i = 1; i <= w; i++) {
                dp[i][0] = 0;
                prefix[i][0] = 0;

                int u = b[i - 1];  // Length of the current block

                for (int j = 1; j <= k - 1; j++) {
                    int high = j - 1;
                    int low = max(0, j - u);

                    int ok = 0;
                    // Compute the sum of valid ranges with modular arithmetic
                    if (low >= 0 && high >= 0) {
                        if (low - 1 >= 0) {
                            ok = (prefix[i - 1][high] - prefix[i - 1][low - 1] + MOD) % MOD;
                        } else {
                            ok = prefix[i - 1][high] % MOD;
                        }
                    }

                    dp[i][j] = ok;

                    // Update the prefix sum array with modular arithmetic
                    prefix[i][j] = (dp[i][j] + prefix[i][j - 1]) % MOD;
                }
            }

            // Sum all valid ways modulo MOD
            for (int j = 1; j <= k - 1; j++) {
                z = (z + dp[w][j]) % MOD;
            }

            // Reset dp and prefix arrays (optional, for cleaner code)
            for (int i = 0; i <= w; i++) {
                for (int j = 0; j <= k - 1; j++) {
                    dp[i][j] = 0;
                    prefix[i][j] = 0;
                }
            }
        }

        // Return the result with modular arithmetic to avoid overflow
        return (d - z + MOD) % MOD;  // Handle negative mod
    }
};