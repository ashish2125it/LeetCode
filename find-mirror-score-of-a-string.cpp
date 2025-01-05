class Solution {
public:
    long long calculateScore(string s) {
        long long ans = 0, n = s.length();
        map<char, vector<int>> mp;

        for (int i = 0; i < n; i++) {
            char c = s[i];
            char r = char('a' + 26 - (s[i] - 'a') - 1); 
            
            if (mp.find(r) != mp.end() && !mp[r].empty()) {
               
                ans += (i - mp[r].back());
                mp[r].pop_back();
            }
           else
            mp[c].push_back(i);
        }

        return ans;
    }
};
