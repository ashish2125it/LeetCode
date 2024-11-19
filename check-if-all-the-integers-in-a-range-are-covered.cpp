class Solution {
public:
    bool isCovered(vector<vector<int>>& ra, int left, int right) {
         vector<int>v(right+4,0);
         int r = ra.size();
         for(auto& it:ra) 
         {
               if(it[0]<=right)
               v[it[0]]++;
               if(it[1]+1<=right) v[it[1]+1]--;
         }
         for(int i=1;i<=right;i++) v[i] += v[i-1];

         for(int i=left;i<=right;i++) 
         {
            if(v[i]<=0) return 0;
         }
         return 1;
    }
};