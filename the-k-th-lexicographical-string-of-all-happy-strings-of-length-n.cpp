class Solution {
public:
void solve(int i,int n,set<string>&st,string s)
{
    if(i>=n) 
    {
        if(s.length()>0)
        st.insert(s);
        return ;
    }

    if(s.length()==0)
    {
        for(char c='a';c<='c';c++)
        {
            solve(i+1,n,st,s+c);
        }
    }
    else
    {
        for(char c='a';c<='c';c++)
        {
            if(s.back()!=c)
            solve(i+1,n,st,s+c);
        }  
    }
}
    string getHappyString(int n, int k) {
    set<string>st;
    solve(0,n,st,"");    
    int cnt= 1;
    for(auto it:st) 
    cout<<it<<" ";
    for(auto it:st)
    {
        if(cnt==k)
        return it;
        cnt++;
    }
    return "";
    }
};