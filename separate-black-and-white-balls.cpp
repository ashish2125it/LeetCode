class Solution {
public:
    long long minimumSteps(string s) {
     long long ans = 0;
    int cc = 0;
    for (int i = s.length() - 1; i >= 0; i--) {
        if (s[i] == '0') {
            cc++;
        }
        else {
            ans += cc;
        }
    }
    return ans;

    }
};