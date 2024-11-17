class Solution {
public:
    int shortestSubarray(vector<int>& arr, int k) {
          int n=arr.size();
   vector<long >prefixSum(n,0);
   
   prefixSum[0]= arr[0];
   for(int i=1;i<n;i++)
   {
       prefixSum[i] = prefixSum[i-1] + arr[i];
   }
   deque<int>q;
   int minSize =INT_MAX;
   for(int i=0;i<n;i++)
   {
       if(prefixSum[i] >= k)
       minSize = min(minSize,i+1);
       
       while(!q.empty() &&  prefixSum[i]-prefixSum[q.front()] >=k)
       {
           minSize = min(minSize,i-q.front());
           q.pop_front();
           
       }

       while(!q.empty() && prefixSum[i]<prefixSum[q.back()])
       {
           q.pop_back();
       }
       q.push_back(i);
   }
   if(minSize==INT_MAX) return -1;
   return minSize;
    }
};