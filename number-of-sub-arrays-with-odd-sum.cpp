class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
    int n = arr.size();
    unordered_map<int,int>mp;
    int sum =0, mod= (1e9+7);
    int ans= 0;

    mp[0] = 1;
    
    for(int i=0;i<n;i++)
    {
        sum += (arr[i]);

        if(sum%2==0)
        {
          ans = (ans%mod + mp[1]%mod)%mod;
          mp[0]++;
        }
        else
        {
          ans = (ans%mod + mp[0]%mod)%mod;
          mp[1]++;
        }
    }

    return ans;
    }
};