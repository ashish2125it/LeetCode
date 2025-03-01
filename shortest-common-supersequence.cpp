class Solution {
public:

    string shortestCommonSupersequence(string str1, string str2) {
    int  n1 = str1.length();
    int n2 = str2.length();

    vector<vector<int>>dp(n1+1,vector<int>(n2+1,0));


    for(int i=1;i<=n1;i++)
    {
        for(int j=1;j<=n2;j++)
        {
            if(str1[i-1]==str2[j-1])
            {
                dp[i][j] = 1 + dp[i-1][j-1];
            }
            else
            {
                dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }

    // for(int i=1;i<=n1;i++)
    // {
    //     for(int j=1;j<=n2;j++)
    //     cout<<dp[i][j]<<" ";
    //     cout<<endl;
    // }

    // store the LCS
    
    string temp = "";
    int i=n1,j=n2;

    while(i>0 && j>0)
    {
        if(str1[i-1]==str2[j-1])
        {
            temp += str1[i-1];
            i--;
            j--;
        }
        else
        {
            if(dp[i-1][j] > dp[i][j-1])
           {
            temp += str1[i-1];
             i--;
           }
            else
            {
            temp += str2[j-1];
            j--;
            }
        }
    }

   // cout<<"temp is "<<temp;

    while(i>0)
    {
        temp += str1[i-1];
        i--;
    }

    while(j>0)
    {
        temp += str2[j-1];
        j--;
    }

    reverse(temp.begin(),temp.end());

    return temp;


    }
};