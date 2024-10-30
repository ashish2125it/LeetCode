

class Solution {
public:
   
    long long findGcd(long long a, long long b) {
        while (b != 0) {
            long long temp = b;
            b = a % b;
            a = temp;
        }
        return a;
    }

    
   long long findLcm(long long a, long long b) {
    return a / findGcd(a, b) * b;
}

    long long maxScore(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) {
            return 0;
        }
        if (n == 1) {
            return static_cast<long long>(nums[0]) * nums[0];
        }

        vector<long long> preGcd(n), sufGcd(n);
        vector<long long> preLcm(n), sufLcm(n);

        
        preGcd[0] = nums[0];
        sufGcd[n - 1] = nums[n - 1];
        preLcm[0] = nums[0];
        sufLcm[n - 1] = nums[n - 1];

        // Calculate prefix GCDs and LCMs
        for (int i = 1; i < n; i++) {
            preGcd[i] = findGcd(preGcd[i - 1], nums[i]);
            preLcm[i] = findLcm(preLcm[i - 1], nums[i]);
        }

        // Calculate suffix GCDs and LCMs
        for (int i = n - 2; i >= 0; i--) {
            sufGcd[i] = findGcd(sufGcd[i + 1], nums[i]);
            sufLcm[i] = findLcm(sufLcm[i + 1], nums[i]);
        }

        // Calculate maximum score
        long long maxScore = preGcd[n - 1] * preLcm[n - 1] ;
        
        for (int i= 0; i < n; i++) {
            long long currScore;
            if (i == 0) {
                currScore = sufGcd[1] * sufLcm[1];
                maxScore = max(maxScore, currScore);
                continue;
            }
            if (i == n - 1) {
                currScore = preGcd[n - 2] * preLcm[n - 2];
                maxScore = max(maxScore, currScore);
                continue;
            }
            long long gcd = findGcd(preGcd[i - 1], sufGcd[i + 1]);
            long long lcm = findLcm(preLcm[i - 1], sufLcm[i + 1]);
            currScore = gcd * lcm;
            maxScore = max(maxScore, currScore);
        }
        
        return maxScore;
    }
};
