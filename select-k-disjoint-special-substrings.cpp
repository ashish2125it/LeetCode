class Solution {
public:
    bool maxSubstringLength(string s, int k) {
    int n = s.length();
    if(k==0) return 1;
    unordered_map<char,int>first,last;
    for(int i=0;i<n;i++)
    {
        if(first.find(s[i])==first.end())
        first[s[i]] = i;
        last[s[i]] = i;
    }

    vector<vector<int>>interval;
    for(int i=0;i<n;i++)
    {
        if(i!=first[s[i]]) continue;

        int left = i, right = last[s[i]];
        bool valid = true;
        for(int j=left;j<=right;j++)
        {
            if(first[s[j]] < left)
            {
                valid = false;
                break;
            }

            right = max(right,last[s[j]]);
        }

        if(right-left+1!=n && valid)
        {
            interval.push_back({left,right});
        }

    }

     sort(interval.begin(),interval.end(),[](auto &a,auto &b)
     {
        return a[1] < b[1];
     }); // based on last occ
     int cnt= 1;
     if(interval.size()==0) return false;
     int start = interval[0][0], end = interval[0][1];
     n = interval.size();
     for(int i=1;i<n;i++)
     {
         if(interval[i][0] > end)
         {
            cnt++;
            end = interval[i][1];
         }
         else
         end = max(end,interval[i][1]);
     }


     return cnt>=k;

    }
};