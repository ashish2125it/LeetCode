class Solution {
public:
    vector<string> stringSequence(string t) {
     vector<string>ans;
     int n = t.length();
     string s = "";
     for(int i=0;i<n;i++)
     {
        for(int j=0;j<26;j++)
        {
            s += char('a'+j);
            ans.push_back(s);
            if(s[i]==t[i])
            break;
            s.pop_back();
        }
     }
     return ans;

    }
};