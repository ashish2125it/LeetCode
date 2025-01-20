class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
    int n = mat.size(), m = mat[0].size();
    unordered_map<int,vector<int>>row;
    unordered_map<int,vector<int>>col;
    unordered_map<int,pair<int,int>>grid;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            grid[mat[i][j]] = {i,j};
        }
    }

    for(int i=0;i<n*m;i++)
    {
        pair<int,int>p = grid[arr[i]];
        int Row = p.first;
        int Col = p.second;
        row[Row].push_back(arr[i]);
        if(row[Row].size()==m) return i;
        col[Col].push_back(arr[i]);
        if(col[Col].size()==n) return i;
    }
    return -1;
    }
};