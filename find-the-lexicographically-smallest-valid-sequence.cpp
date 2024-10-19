class Solution {
public:
    vector<int> validSequence(string w1, string w2) {
     int n1 = w1.length(),n2 = w2.length();
     vector<int>s(n2,-1);
     int i=n1-1,j= n2-1;
     int op = 1;
     while(i>=0 && j>=0)
     {
        if(w1[i]==w2[j])
        {
            s[j] = i;
            j--;
            i--;
        }
        else
        i--;
     }

     i=0,j=0;
    
     vector<int>ans(n2,-1);
     vector<int>temp;
     while(i<n1 && j<n2)
     {
          if(w1[i]!=w2[j])
          {
              if(op==1)
              {
                 if(j+1<=n2)
                 {
                 if(j+1==n2)
                 {
                    ans[j] = i;
                    return ans;
                 }
                 int index = s[j+1];
                 if(index>i)
                 {
                    ans[j] = i;
                    op =0;
                    i++;
                    j++;
                 }
                 else
                 i++;
                 }
                 else
                 i++;
              }
              else
              i++;
          }
          else
          {
            ans[j] = i;
            i++;
            j++;
          }
     }
     
     if(j<n2) return temp;
     
     return ans;
    }
}; 