class Solution {
public:
    int longestSubsequence(string s, int k) {
        int power = 0;
        int count = 0;
        int n = s.size();
        long long val = 0;
        for(int i = n - 1; i >= 0; i--) {
            if(s[i] == '0') {
                count++;
            } else {
                if(power < 32) {
                    val += (1LL << power);
                    if(val <= k) count++;
                }
            }
            power++;
        }
        return count;
    }
};