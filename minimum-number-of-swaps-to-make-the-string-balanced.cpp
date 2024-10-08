class Solution {
public:
    int minSwaps(string s) {
    int n = s.length();
    int open =0,close= 0;
    int ans= 0;
    for(int i=0;i<n;i++)
    {
        if(s[i]=='[') open++;
        else close++;

        if(close>open)
        {
            ans++;
            close--;
            open++;
        }
    } 

    return ans;
    }
};