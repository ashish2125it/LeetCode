class Solution {
public:
    vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& q) {

     int n = items.size();
     sort(items.begin(),items.end());
     vector<int>maxi(n);
     maxi[0] = items[0][1];
     for(int i=1;i<n;i++) 
     maxi[i] = max(maxi[i-1],items[i][1]);
     vector<int>res;

     int size =  q.size();

     for(int i=0;i<size;i++)
     {
        int p = q[i];
        int s =0,e =  n-1;
        int ans =0;
        while(s<=e)
        {
            int mid = (s+e)/2;
            if(items[mid][0] > p)
            {
                e = mid-1;
            }
            else if(items[mid][0]<=p)
            {
                ans = maxi[mid] ;
                s= mid+1; 
            }
        }

        res.push_back(ans);
     }

     return res;
    }
};