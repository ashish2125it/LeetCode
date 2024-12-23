class Solution {
public:
    bool canTransformAlt(string& s, int numOps, int targetLength, char startChar) {
        for (char ch : s) {
            if (ch != startChar) numOps--;
            startChar = startChar ^ 1;
        }
        return (numOps >= 0);
    }

    bool isPossible(string& s, int numOps, int maxLength) {
        if (maxLength == 1) 
            return canTransformAlt(s, numOps, maxLength, '1') || canTransformAlt(s, numOps, maxLength, '0');

        int repeatCount = 0;
        for (int i = 0, lastChar = -1; i < s.size(); ++i) {
            if (s[i] == lastChar) 
                repeatCount++;
            else {
                numOps -= repeatCount / (maxLength + 1);
                lastChar = s[i];
                repeatCount = 1;
            }
        }
        numOps -= repeatCount / (maxLength + 1);
        return (numOps >= 0);
    }


    int minLength(string s, int numOps) {
        int left = 1, right = s.size(), ans = s.size();
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (isPossible(s, numOps, mid)) {
                ans = mid;
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return ans;
    }
};