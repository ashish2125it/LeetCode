class Solution {
public:
    int minimumTimeToInitialState(string word, int k) {
        string temp=word;
        int n=word.length();
        
       int ans=0,i=0;
        while(1){
            ans++;
            int j=i+k,m=0;
            while(j<n && temp[m]==word[j]){
               j++;
              m++;
                }
            if(j>=n)
                return ans;
            i+=k;
            
            }
       return 0;
    }
};