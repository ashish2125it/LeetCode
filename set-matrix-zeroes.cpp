class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
    int n = matrix.size(),m = matrix[0].size();
    set<int>row,col;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(matrix[i][j]==0)
            {
                row.insert(i);
                col.insert(j);
            }
        }
    }

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(row.find(i)!=row.end() || col.find(j)!=col.end())
            matrix[i][j] = 0;
        }
    }

    }
};