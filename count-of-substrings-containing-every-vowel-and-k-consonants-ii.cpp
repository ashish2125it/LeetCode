class Solution {
    long long solve(string &w, int k) {
        int i = 0, j = 0;
        int c1 = 0, c2 = 0, c3 = 0, c4 = 0, c5 = 0, c6 = 0;
        long long ans = 0;
        int n = w.length();
        
        while (j < n) {
    
            if (w[j] == 'a') c1++;
            else if (w[j] == 'e') c2++;
            else if (w[j] == 'i') c3++;
            else if (w[j] == 'o') c4++;
            else if (w[j] == 'u') c5++;
            else c6++;

           
            while (c1 >= 1 && c2 >= 1 && c3 >= 1 && c4 >= 1 && c5 >= 1 && c6 >= k) {
                ans += (n - j);  
               
                if (w[i] == 'a') c1--;
                else if (w[i] == 'e') c2--;
                else if (w[i] == 'i') c3--;
                else if (w[i] == 'o') c4--;
                else if (w[i] == 'u') c5--;
                else c6--;
                i++;
            }
            j++;  
        }
        
        return abs(ans);
    }

public:
    long long countOfSubstrings(string word, int k) {
       
        return abs(solve(word, k) - solve(word, k + 1));
    }
};
