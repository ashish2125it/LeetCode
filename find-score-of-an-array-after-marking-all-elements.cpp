class Solution {
public:
    long long findScore(vector<int>& nums) {
      priority_queue<pair<int,int>, std::vector<pair<int,int>>, greater<pair<int,int>>> pq;
      int n = nums.size();
      long long ans= 0;
      for(int i=0;i<n;i++) pq.push({nums[i],i});
      
      map<int,int>mp; 
      while(pq.size())
      {
         int ele = pq.top().first;
         int ind = pq.top().second;
         pq.pop();

         if(mp.find(ind)==mp.end())
         {
            ans += ele;
            mp[ind] = 1;
            if(ind-1>=0)
            mp[ind-1] = 1;
            if(ind+1<n)
            mp[ind+1] = 1;
         }
      }  

      return ans;
    }
};