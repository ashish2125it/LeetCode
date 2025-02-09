class Solution {
public:
    vector<int> assignElements(vector<int>& groups, vector<int>& el)   
    {
        int  n = groups.size();
        unordered_map<int,vector<int>>mp;
        unordered_map<int,int>mp1;
        for(int i=0;i<el.size();i++)
        {
            if(mp1.find(el[i])==mp1.end())
            mp1[el[i]] = i; 
        }

        for(int i=0;i<n;i++)
        {
            int num = groups[i];
            for(int j=1;j*j<=num;j++)
            {
                if(num%j==0)
                {
                mp[num].push_back(j);
                mp[num].push_back(num/j);
                }
            }
        }

        vector<int>ans;
        for(int i=0;i<n;i++)
        {
            vector<int>temp = mp[groups[i]];
            int mini = INT_MAX;
            for(int j=0;j<temp.size();j++)
            {
                 if(mp1.find(temp[j])!=mp1.end())
                 mini = min(mini,mp1[temp[j]]);
            }

            if(mini!=INT_MAX)
            ans.push_back(mini);
            else 
            ans.push_back(-1);
        }

         return ans;

    }
};