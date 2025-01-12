class Solution {
public:
    bool canBeValid(string s, string l) {
    int n = s.length();
    if(n%2!=0) return 0;
    if(s[0]==')' && l[0]=='1') return 0;
    
    stack<pair<char,char>>st;
    for(int i=0;i<n;i++)
    {
        if(s[i]=='(')
        {
           st.push({s[i],l[i]});
        }
        else
        {
            if(st.empty())
            {
                if(l[i]=='0')
                {
                   st.push({'(',0});
                }
                else
                return 0;
            }
            else
            {
                if(st.top().first=='(')
                st.pop();
            }
        }
    }
    
    if(st.size()%2!=0) return 0;
    if(st.size()==0) return 1;
   
    while(!st.empty()) 
    {
    char close = st.top().second;
    st.pop();
    char open = st.top().second;
       st.pop();
       if(close=='1') 
       return 0;
      
    }

    return 1;



    }
};