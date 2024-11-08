class Solution {
public:
    void solve(vector<vector<int>>& min_cost, vector<char>& o, vector<char>& c, vector<int>& cost) {
       
        for (int i = 0; i < cost.size(); i++) {
            min_cost[o[i] - 'a'][c[i] - 'a'] = min(min_cost[o[i] - 'a'][c[i] - 'a'], cost[i]);
        }

      
        for (char k = 'a'; k <= 'z'; k++) {
            for (char i = 'a'; i <= 'z'; i++) {
                for (char j = 'a'; j <= 'z'; j++) {
                    if (min_cost[i - 'a'][k - 'a'] != 1e9 && min_cost[k - 'a'][j - 'a'] != 1e9) {
                        min_cost[i - 'a'][j - 'a'] = min(min_cost[i - 'a'][j - 'a'], min_cost[i - 'a'][k - 'a'] + min_cost[k - 'a'][j - 'a']);
                    }
                }
            }
        }
    }

    long long minimumCost(string s, string t, vector<char>& o, vector<char>& c, vector<int>& cost) {
        vector<vector<int>> min_cost(26, vector<int>(26, 1e9));
        
       
        for (int i = 0; i < 26; i++) min_cost[i][i] = 0;

      
        solve(min_cost, o, c, cost);

       
        long long  ans = 0;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] != t[i]) {
                if (min_cost[s[i] - 'a'][t[i] - 'a'] == 1e9) {
                    
                    return -1;
                }
                ans += min_cost[s[i] - 'a'][t[i] - 'a'];
            }
        }
        
        return ans;
    }
};
