class Solution {
public:
    long long minCost(vector<int>& arr, vector<int>& brr, long long k) {
     long long ans= k;
 int n = arr.size();
       long long ans1 = 0;
        for(int i=0;i<n;i++)
            {
                 ans1 += max(arr[i],brr[i]) - min(arr[i],brr[i]);
            }
        int cnt= 0;
       
    for(int i=0;i<n;i++)
        {
            if(arr[i]==brr[i])
                cnt++;
        }
        if(cnt==n) return 0;
        vector<int>temp(n);
        for(int i=0;i<n;i++)
            temp[i] = arr[i];
        sort(temp.begin(),temp.end());
        sort(brr.begin(),brr.end());
        
        cnt =0;
        for(int i=0;i<n;i++)
            {
                if(temp[i]==arr[i]) 
                    cnt++;
            }
        
       for(int i=0;i<n;i++)
           {
               long long op1 =0;
               if(temp[i]!=brr[i])
               op1 = max(temp[i],brr[i]) - min(temp[i],brr[i]);
               ans +=op1;
           }
        return min(ans,ans1);
    }
};