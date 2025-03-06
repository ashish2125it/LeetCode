class Solution {
public:
    int longestBeautifulSubstring(string word) {
        int n = word.length();
        int maxLen = 0;
        int i = 0; // Start index of the substring

        while (i < n) {
            if (word[i] != 'a') {
                i++;  // Skip invalid starting characters
                continue;
            }

            int j = i; // Pointer to traverse the substring
            int count = 1; // Count distinct vowels
            while (j + 1 < n && word[j] <= word[j + 1]) { // Ensure increasing or same vowels
                if (word[j] != word[j + 1]) count++; // Count unique vowels
                j++;
            }

            // Check if all 5 vowels are present
            if (count == 5) {
                maxLen = max(maxLen, j - i + 1);
            }

            // Move `i` to the next possible start position
            i = j + 1;
        }

        return maxLen;
    }
};
