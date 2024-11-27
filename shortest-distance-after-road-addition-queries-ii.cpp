class Solution {
public:
    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& q) {
        int m = q.size();
        vector<int>ans(m);
        set<int>s;
        for(int i=0;i<n;i++) s.insert(i);

        for(int i=0;i<m;i++)
        {
            int left = q[i][0]+1;
            int right = q[i][1]-1;
    auto itLeft = s.lower_bound(left); // First element >= left
    auto itRight = s.upper_bound(right); // First element > right

    // Erase the range [itLeft, itRight)
    s.erase(itLeft, itRight);
    ans[i] = s.size()-1;
        }

        return ans;


        


    }
};