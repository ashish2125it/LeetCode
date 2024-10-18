typedef long long int ll;
ll md = 1e9 + 7;
class Solution {
public:
    int numberOfWays(int n, int x7, int y) { ll x = x7;
        vector<vector<ll>> dp(n+1, vector<ll>(x+1, 0));
        dp[1][1] = x;
        for(ll i=2;i<=n;i++){
            for(ll j=1;j<=min(x,i);j++){
                dp[i][j] = (dp[i-1][j]*j + dp[i-1][j-1]*(x-(j-1)))%md;
            }
        } ll c = 0 ; ll y1 = y ; 
        for(ll v=1;v<=x;v++){ c = (c + dp[n][v]*y1)%md ; 
            //cout<<dp[n][v]<<" "<<y1<<"\n";

            y1 = (y1*y)%md;
        }
        return c;
        
    }
};