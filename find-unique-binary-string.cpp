class Solution {
public:
void solve(int i,unordered_set<string>&st,string temp,string &ans,int n)
{
    if(i>=n)
    {
        if(st.find(temp)==st.end())
        ans = temp;
        return ;
    }

    solve(i+1,st,temp+'0',ans,n);
    solve(i+1,st,temp+'1',ans,n);
}
    string findDifferentBinaryString(vector<string>& nums) {
    string ans = "";
    string temp = "";
    int n = nums.size();
    unordered_set<string>st;
    for(auto it:nums)
    st.insert(it); 
    solve(0,st,temp,ans,n);
    return ans;
    }
};