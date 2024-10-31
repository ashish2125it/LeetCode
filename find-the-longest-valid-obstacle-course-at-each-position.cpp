class Solution {
public:
    vector<int> longestObstacleCourseAtEachPosition(vector<int>& ob) {
    int n = ob.size();
    vector<int> ans(n);
    vector<int>t;
    t.push_back(ob[0]);
    ans[0] = 1;
    for(int i=1;i<n;i++)
    {
        if(ob[i]>=t.back())
        {
            t.push_back(ob[i]);
            ans[i]= t.size();
        }
        else
        {
            int index = upper_bound(t.begin(),t.end(),ob[i])-t.begin();
            t[index] = ob[i];
            ans[i] = index + 1;
        }
    }
    return ans;

    }
};