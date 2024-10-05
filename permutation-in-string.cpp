class Solution {
public:
bool EqualVector(vector<int>&freq1,vector<int>&freq2)
{
    for(int i=0;i<26;i++)
    {
        if(freq1[i]!=freq2[i]) return 0;
    }
    return 1;
}
    bool checkInclusion(string s1, string s2) {
        int n1 = s1.length(),n2 = s2.length();
        vector<int>freqS1(26,0),freqS2(26,0);
         int i=0,j=0;
         for(auto it:s1)
         freqS1[it-'a']++;

         while(j<n2)
         {
             freqS2[s2[j]-'a']++;
             if(j-i+1==n1)
             {
                 if(EqualVector(freqS1,freqS2)) return 1;
             }

             if(j-i+1<n1)
             {
                  j++;
             }
             else  // equal to greater then
             {
                freqS2[s2[i]-'a']--;
                i++;
                j++;
             }

         }
         return 0;
    }
};