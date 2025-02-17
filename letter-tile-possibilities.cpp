class Solution {
public:
unordered_set<string>st;
void solve(int i,int n,string t,string &s)
{
    if(i>=n)
    {
        if(s.length()>0)
        {
        string temp = s;
        sort(temp.begin(),temp.end());    
        st.insert(temp);
        }
        return ;
    }

   s += t[i];
   solve(i+1,n,t,s);
   s.pop_back();
   solve(i+1,n,t,s);

}
    int numTilePossibilities(string tiles) {
    int n = tiles.length();

   
   
    string s = "";
    
    vector<int>fact(n+1,1);
    for(int i=2;i<=n;i++)
    {
        fact[i] = fact[i-1]*i;
    }

    solve(0,n,tiles,s);
     for(auto it:st)
    cout<<it<<" ";
    int ans= 0;

    for(auto  it:st)
    {
        string t = it ;
        unordered_map<char,int>mp;
        for(int i=0;i<t.length();i++)
        mp[t[i]]++;
        
        int d =1;
        for(auto m:mp)
        {
            if(m.second>1)
            d = d*fact[m.second];
        }

        ans =  ans + (fact[t.length()])/d;
    }

    return ans;
    
    }
};