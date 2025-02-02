class Solution {
public:
    int maxDistance(string s, int k) {
        int n = s.length();
        int x = 0, y = 0;
        int z= k;
        int s1=0,n1=0,w1=0,e1=0;
        int ans= 0;
        
        for (int i = 0; i < n; i++) {
            if (s[i] == 'N') 
            {
                y++;
                n1++;
               
            }
            else if (s[i] == 'S')
            {
                y--;

                s1++;
            }
            else if (s[i] == 'E')
            {
                x++;
                e1++;
            }
            else if (s[i] == 'W')
            {
                x--;
                w1++;
            }
            

            int temp = abs(x) + abs(y);

            int mini1 =  min(n1,s1);
            if(mini1 > k)
            {
                temp += 2*(k);
                k =0;
            }
            else
            {
                temp += 2*(mini1);
                k -= mini1;
            }

            int mini2 = min(e1,w1);
            if(k)
            {
                temp += 2*(min(k,mini2));
            }
            
            k = z;
              ans = max(ans,temp);  
            
        }

        
      
        
        return ans;
    }
};
