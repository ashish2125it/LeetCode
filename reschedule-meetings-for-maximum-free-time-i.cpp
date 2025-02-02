class Solution {
public:
    int maxFreeTime(int eventTime, int k, vector<int>& st, vector<int>& et) {
        
         int n = st.size();
        vector<int> gaps(n + 1);

        // Calculate the first and last gap separately
        gaps[0] = st[0];  // Free time before the first meeting
        gaps[n] = eventTime - et[n - 1];  // Free time after the last meeting

        // Compute gaps between meetings
        for(int i = 1; i < n; i++){
            gaps[i] = st[i] - et[i - 1];
        }

       
        vector<int> pre(n + 2, 0);
        for(int i = 1; i <= n + 1; i++){
            pre[i] = pre[i - 1] + gaps[i - 1];
        }

        int ans = 0 ;
        int j = k+2 ;
        int i = 0 ;
        ans = pre[k+1] ;
       
        
        while(j<=n+1)
        {
            ans = max(ans,pre[j]-pre[j-(k+1)]);
            j++;
            i++;
        }
        

        return ans;
    }
};