class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
      int n = A.size();
    vector<int>ans(n,0);
    unordered_map<int,int>mp;
    int cnt= 0;
    if(A[0]==B[0])
    {
        mp[A[0]]++;
        cnt++;
        ans[0] = cnt;
   }
        
        mp[A[0]]++;
        mp[B[0]]++;
        for(int i=1;i<n;i++)
        {
            if(A[i]==B[i])
                cnt++;
            else
            {
                if(mp.find(A[i])!=mp.end())
                    cnt++;
                if(mp.find(B[i])!=mp.end())
                    cnt++;
                
            }
            mp[A[i]]++;
            mp[B[i]]++;
            ans[i] = cnt;
        }
        return ans;
        
        
        
    }
};