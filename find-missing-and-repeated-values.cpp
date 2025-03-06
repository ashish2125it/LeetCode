class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
           int n1=grid.size();
        int miss1,doub1,sum1=0;
        vector<int>temp1(n1*n1+1,0);
    
        for(int i=0;i<n1;i++){
            for(int j=0;j<n1;j++){
                temp1[grid[i][j]]++;
                if(temp1[grid[i][j]]==2)
                    doub1=grid[i][j];
            }
        }
        for(int i=1;i<n1*n1+1;i++){
            if(temp1[i]==0){
                miss1=i;
                break;
            }
            
        }
        return {doub1,miss1};

    }
};