class Solution {
public:
    int maxTurbulenceSize(vector<int>& arr) {
    int n = arr.size();
    vector<int>inc(n,1),dec(n,1);
    int ans= 1;

    for(int i=1;i<n;i++)
    {
       
       if(arr[i]>arr[i-1])
       {
           inc[i] = max(inc[i],1+dec[i-1]);
       }
       else if(arr[i-1]>arr[i])
       {
        dec[i] = max(dec[i],1+inc[i-1]);
       }

      ans = max(ans, max(inc[i],dec[i]));
         
    }

    // for(auto it:inc)
    // cout<<it<<" ";
    // cout<<endl;
    // for(auto it:dec)
    // cout<<it<< " ";
     return ans;
    }
};