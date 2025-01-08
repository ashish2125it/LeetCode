class Solution {
public:
    bool check(string s1,string s2)
    {
        if(s1.size()>s2.size()) return 0;
        for(int i=0;i<s1.size();i++)
        {
            if(s1[i]!=s2[i]) return 0;
        }
        int j = s2.size()-1;
        for(int i=s1.size()-1;i>=0;i--)
        {
            if(s1[i]!=s2[j]) return 0;
            j--;
        }
        return 1;
    }
    int countPrefixSuffixPairs(vector<string>& words) {
    int n= words.size();
    int cnt= 0;
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            if(check(words[i],words[j]))cnt++;
        }
    }
        return cnt;
    }
};