class Solution {
public:
    int minTimeToReach(vector<vector<int>>& mo) {
    int n = mo.size(),m = mo[0].size();
    int dx[4] = {-1,0,1,0};
    int dy[4] = {0,1,0,-1};
    set<tuple<int,int,int>>st; // {distance,x,y}
    st.insert({0,0,0});
    vector<vector<int>>dist(n,vector<int>(m,INT_MAX));
    dist[0][0] = 0;
    while(!st.empty())
    {
        auto [distance,x,y] = *st.begin();
        st.erase(*st.begin());

        for(int i=0;i<4;i++)
        {
            int new_x = x + dx[i];
            int new_y = y + dy[i];
            if(new_x>=0 && new_y>=0 && new_x<n && new_y<m && dist[new_x][new_y] > max(distance+1 ,mo[new_x][new_y]+1 ) )
            {
                st.erase({distance,new_x,new_y});
                dist[new_x][new_y] = max(distance+1,mo[new_x][new_y]+1 ); 
                st.insert({dist[new_x][new_y],new_x,new_y});
            }
        }



    }

    return dist[n-1][m-1];
    }
};