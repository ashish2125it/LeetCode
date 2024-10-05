class Solution {
public:
    string smallestString(string s) {
    string ans ="";
    int start= 0;
    int n = s.length();
    for(int i=0;i<n;i++)
    {
        if(start==1)
        {
            if(s[i]=='a')
            {
                ans += s[i];
                start = -1;
            }
            else
            ans += char(s[i]-1);
        }
        else if(start==0)
        {
            if(s[i]!='a')
            {
              start = 1;
              ans += char(s[i]-1);
            }
            else
            ans += s[i];
        }
        else if(start==-1)
        ans += char(s[i]) ;
    }
    if(start==0)
    {
        s[n-1] = 'z';
        return s;
    }

    return ans;
    }
};