class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
    int n = s1.length();
    int cnt= 0;
    map<char,int>mp1,mp2;

    for(auto it:s1)
    mp1[it]++;
    
    for(auto it:s2)
    {
        mp2[it]++;
    }

    for(auto it:mp1)
    {
        
            if(mp2[it.first]!=it.second) 
            return 0;
    }


    for(int i=0;i<n;i++)
    {
        if(s1[i]!=s2[i])
        cnt++;
        if(cnt>2) return 0;
    }    
    return 1;
    }
};