class Solution {
public:
    string answerString(string word, int f) {
    int n  = word.length();
    if(f==1) return word;
    string ans = "";
    char c = 'a';
    for(auto it:word)
    c= max(c,it);

    for(int i=0;i<n;i++)
    {
        if(word[i]==c)
        {
            int len = min(n-i,n-f+1);
            string st = word.substr(i,len);

            if(st>ans)
            {
                ans = st;
            }
        }
    }

    return ans;


    }
};