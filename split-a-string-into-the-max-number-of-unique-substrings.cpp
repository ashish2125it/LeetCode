class Solution {
int solve(int i,string &s,unordered_set<string>&st,string temp)
{
    if(i>=s.size()) return 0;

    temp += s[i];

    int opt1 =-1e9,opt2= -1e9;
    if(st.find(temp)==st.end())
    {
          st.insert(temp);
          opt1 = 1 + solve(i+1,s,st,"");
          st.erase(temp);
          opt2 =  solve(i+1,s,st,temp);
    }
    else
    {
          opt2 =  solve(i+1,s,st,temp);
    }

    return max(opt1,opt2);

}
public:
    int maxUniqueSplit(string s) {
    unordered_set<string>st;
    string temp = "";
    return solve(0,s,st,temp);
    }
};