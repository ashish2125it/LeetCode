class Solution {
public:
    int minAddToMakeValid(string s) {
    int n = s.length();
    //  int in =0,out= 0;
    //  for(int i=0;i<n;i++)
    //  {
    //      if(s[i]=='(')
    //      in++;
    //      else
    //      out++;

    //      if(in==out)
    //      {
    //          in=0;
    //          out=0;
    //      }
    //      else
    //      {
    //          if(in>out)
    //         { in = in - out;
    //          out =0;
    //         }
    //         else
    //         {
    //             out = out - in;
    //             in  =0;
    //         }
    //      }

    //  }
    //  if(in) return in;
    //  if(out) return out;
    //  return 0;
    //  stack<char>st;
    //  for(int i=0;i<n;i++)
    //  {
    //      if(s[i]=='(')
    //      {
    //          st.push(s[i]);
    //      }
    //      else
    //      {
    //          if(!st.empty() && st.top()=='(')
    //          st.pop();
    //          else
    //          st.push(s[i]);
    //      }
    //  }
    //  return st.size();
       int bal =0;
       int cnt= 0;
       for(int i=0;i<n;i++)
       {
           if(s[i]=='(')
           bal++;
           else
           bal--;

           if(bal==-1)
           {
               bal =0;
               cnt++;
           }
       }
       return cnt+ bal;
    }
};