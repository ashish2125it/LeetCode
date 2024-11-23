class Solution {
public:
    
    void dfs(int src, vector<vector<int>>& gr, vector<int>& vis,int &cnt) {
        vis[src] = true;
        cnt++;
        for (int i : gr[src]) {
            if (!vis[i])
                dfs(i, gr, vis,cnt);
        }
    }
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& ins) {

        vector<vector<int>> gr(n);
        int cnta=0;
        for (const auto& in : ins) {
            int u = in[0];
            int v = in[1];
            gr[u].push_back(v);
        }

        vector<int> vis(n, 0);

        dfs(k, gr, vis,cnta);

        vector<vector<int>> gr2(n);
        int cntb=0;
        for (const auto& in : ins) {
            int u = in[0];
            int v = in[1];
            gr2[u].push_back(v);
            gr2[v].push_back(u);
        }
        vector<int> vis2(n, 0);
        dfs(k, gr2, vis2,cntb);

        vector<int> ans;
       
        if(cnta==cntb){
            for(int i=0;i<n;i++)
              if(!vis[i]) ans.push_back(i);
        }else{
            for(int i=0;i<n;i++)
              ans.push_back(i);
        }
      
        return ans;
    }
};