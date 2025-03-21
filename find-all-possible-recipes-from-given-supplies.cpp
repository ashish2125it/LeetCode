class Solution {
public:
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
        unordered_map<string,bool>mp;
        for(auto it:supplies)
            mp[it]=true;
          vector<string>ans;
        int n=recipes.size();
        vector<bool>v(n,0);
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
            if(v[j]==0){
                bool found=1;
                for(auto it:ingredients[j]){
                    if(mp[it]==0){
                        found=0;
                        break;
                    }
                }
                if(found==1){
                    mp[recipes[j]]=1;
                    v[j]=1;
                    ans.push_back(recipes[j]);
                }
                
            }
        }
            if(ans.size()==n)
                break;
        }
      
       
        return ans;
        
    }
};