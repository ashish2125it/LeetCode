class Solution {
public:
    int minDeletions(string s) {
        int n = s.length();
        map<char, int> f;
        map<int, int> cnt;

        // Count the frequency of each character
        for (int i = 0; i < n; i++) {
            f[s[i]]++;
        }

        // Count how many times each frequency appears
        for (auto it : f) {
            cnt[it.second]++;
        }

        int ans = 0;

        // Traverse the frequencies in reverse order
        for (auto it = cnt.rbegin(); it != cnt.rend(); ) {
            int frequency = it->first;
            int count = it->second;

            if (count > 1) {
                ans += (count - 1);  // Calculate the deletions needed
                int reducedFrequency = frequency - 1;

                if (reducedFrequency > 0) {
                    cnt[reducedFrequency] += (count - 1);  // Shift extra counts to lower frequency
                }
            }

            // Safely erase the current frequency
            auto toErase = it; 
            ++it;  // Increment the iterator before erasing
            cnt.erase(toErase->first);
        }

        return ans;
    }
};
