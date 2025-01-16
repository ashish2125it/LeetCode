class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
     vector<vector<string>>ans;
     map<vector<int>,vector<int>>t;
     int n =  strs.size();
     for(int i=0;i<n;i++)
     {
        string s = strs[i];
        vector<int>f(26,0);
        for(int j=0;j<s.length();j++)
        f[s[j]-'a']++;

        t[f].push_back(i);
     }

     for(auto it:t)
     {
        vector<int>v = it.second;
        int size = v.size();
        vector<string>temp;
        for(auto i:v)
        temp.push_back(strs[i]);

        ans.push_back(temp);
     }

     return ans;
    }
};