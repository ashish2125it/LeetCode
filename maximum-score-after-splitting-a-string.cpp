class Solution {
public:
    int maxScore(string s) {
    int n = s.length();
    vector<int>one(n,0),zero(n,0);
    if(s[0]=='0') zero[0] = 1;
    for(int i=1;i<n;i++)
    {
        if(s[i]=='0')
        zero[i] = 1 + zero[i-1];
        else
        zero[i] = zero[i-1];

    }
    if(s[n-1]=='1') one[n-1] = 1;

     for(int i=n-2;i>=0;i--)
    {
        if(s[i]=='1')
        one[i] = 1 + one[i+1];
        else
        one[i] = one[i+1];

    }
    int maxi =0;
    for(int i=0;i<n-1;i++)
    {
        maxi = max(maxi,zero[i]+one[i+1]);
    }
   return maxi;


    }
};