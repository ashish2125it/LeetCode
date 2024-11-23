#define ll long long
class Solution {
public:
    long long shiftDistance(string s, string t, vector<int>& nextCost, vector<int>& previousCost) {
        ll ans = 0; 
        
        for (int i = 0; i < s.length(); i++) {
            if (s[i] != t[i]) {
                int start = s[i] - 'a';
                int end = t[i] - 'a';  

                
                ll forwardCost = 0;
                for (int k = start; k != end; k = (k + 1) % 26) {
                    forwardCost += nextCost[k];
                }

                ll backwardCost = 0;
                for (int k = start; k != end; k = (k - 1 + 26) % 26) {
                    backwardCost += previousCost[k];
                }

                ans += min(forwardCost, backwardCost);
            }
        }

        return ans; 
    }
};
