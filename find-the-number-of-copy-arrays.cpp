class Solution {
public:
    int countArrays(vector<int>& o, vector<vector<int>>& b) {
    int n = o.size();
    int lower = b[0][0] ,higher = b[0][1] ; 

    int prev_diff=  0;

    for(int i=1;i<n;i++)
    {
        int diff = o[i]- o[i-1];
        diff += prev_diff;

        lower =  max(lower, b[i][0]-diff);
        higher = min(higher, b[i][1]-diff);

        prev_diff = diff ;

    } 

    if(higher-lower+1<=0) return 0;
    return higher-lower+1;

    }
};