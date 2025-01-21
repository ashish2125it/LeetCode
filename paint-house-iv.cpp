#define ll long long
class Solution {
public:
    long long minCost(int n, vector<vector<int>>& cost) {
    vector<vector<vector<ll>>>dp(n/2,vector<vector<ll>>(3,vector<ll>(3,INT_MAX)));

    // first fill the first and last row

    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            if(i!=j)
            dp[0][i][j] = cost[0][i] + cost[n-1][j];
        }
    } 


    for(int row=1;row<(n/2);row++)
    {
         // choose current color combination
         for(int i=0;i<3;i++)
         {
            for(int j=0;j<3;j++)
            {
                if(i==j) continue;

                ll prev_cost = INT_MAX;

                // find the prev min cost
                for(int i1=0;i1<3;i1++)
                {
                    for(int j1=0;j1<3;j1++)
                    {
                        if(i!=i1 && j!=j1 && i1!=j1)
                        {
                            prev_cost = min(prev_cost,dp[row-1][i1][j1]);
                        }
                    }
                }

                dp[row][i][j] = cost[row][i] + cost[n-row-1][j] + prev_cost;
                
            }
         }


    }

    ll ans = INT_MAX;
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
        if(i!=j)
        ans = min(ans,dp[(n/2)-1][i][j]);
        }

    }

    return ans;




    }
};