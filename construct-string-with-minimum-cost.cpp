class Solution {
public:
    int solve(int i, const string &t, unordered_map<string, int> &mp, vector<int> &dp) {
        if (i >= t.length()) return 0;
        if (dp[i] != -1) return dp[i];

        int ans = 1e9;
        for (int j = i; j < t.length(); ++j) {
            string s = t.substr(i, j - i + 1);  // Avoid repeated concatenation
            if (mp.find(s) != mp.end()) {
                ans = min(ans, mp[s] + solve(j + 1, t, mp, dp));
                if (ans == mp[s]) break;  // Early exit if cost is already minimal
            }
        }

        return dp[i] = ans;
    }

    int minimumCost(string target, vector<string>& words, vector<int>& costs) {
        unordered_map<string, int> mp;
        for (int i = 0; i < words.size(); ++i) {
            if (mp.find(words[i]) != mp.end()) {
                mp[words[i]] = min(mp[words[i]], costs[i]);
            } else {
                mp[words[i]] = costs[i];
            }
        }

        vector<int> dp(target.size() + 1, -1);
        int ans = solve(0, target, mp, dp);
        return (ans == 1e9) ? -1 : ans;
    }
};
