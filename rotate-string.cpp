class Solution {
public:
void rotate(string& p)
{ 
    char c =p[0];
    for(int i=1;i<p.length();i++)
    {
      p[i-1] =p[i];
    }
    p[p.length()-1] =c;
}
    bool rotateString(string s, string goal)
    {
        for(int i=0;i<s.length();i++)
        {
            if(s==goal)
            return true;
            rotate(s);
        }
        return false;
    }
};