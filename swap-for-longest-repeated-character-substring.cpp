class Solution {
public:
    int maxRepOpt1(string text) {
    int n = text.size();
    if(n==1) return 1;
    vector<int>left(n,1),right(n,1);
    unordered_map<char,int>mp;
    for(auto it:text) mp[it]++;

    int ans= 0 ;

    for(int i=1;i<n;i++)
    {
        if(text[i]==text[i-1])
        left[i] = 1 + left[i-1];

        ans = max(ans,left[i]);
    }

    for(int i=n-2;i>=0;i--)
    {
        if(text[i]==text[i+1])
        right[i] = 1 + right[i+1];

        ans = max(ans,right[i]);
    } 

    

    for(int i=1;i<n-1;i++)
    {
      if(text[i-1]==text[i+1] && text[i]!=text[i-1])
      {
        if(mp[text[i-1]]> left[i-1]+right[i+1])
        {
            ans = max(ans,left[i-1]+right[i+1]+1);
        }
        else if(mp[text[i-1]] == left[i-1]+right[i+1])
        ans = max(ans,left[i-1]+right[i+1]);
      }
      else
      {
           ans = max(ans,left[i]);
           ans = max(ans,right[i]);

           if(text[i-1]!=text[i])
           {
              if(mp[text[i-1]] > left[i-1])
              ans= max(ans,1 + left[i-1]);
           }

           if(text[i]!=text[i+1])
           {
              if(mp[text[i+1]] > right[i+1])
              {
                 ans = max(ans,1 + right[i+1]);
              }
              
                
           }
      }
    }
    
    return ans; 

    }
};