#define ll long long
class Solution {
public:
ll mod = (1e9+7);
ll solve(int i,int n,int m,int k,int last)
{
    if(i==n)
    {
        if(k==0) return 1;
        return 0;
    }


    ll ans= 0 ;

    for(int j=1;j<=m;j++)
    {
        if(last==j)
        {
           ans = (ans%mod + solve(i+1,n,m,k-1,last)%mod)%mod;
        }
        else
        ans = (ans%mod + solve(i+1,n,m,k,j)%mod)%mod;
    }

    return ans%mod;


}
    int countGoodArrays(int n, int m, int k) {
    ll ans = 0;
    for(int i=1;i<=m;i++)
    ans =  (ans%mod + solve(1,n,m,k,i)%mod )%mod;
    
    return ans%mod;
    }
};