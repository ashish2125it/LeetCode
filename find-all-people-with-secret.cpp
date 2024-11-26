class DSU{
    vector<int>parent,rank;
    public:
    DSU(int n)
    {
         parent.resize(n+1);
         rank.resize(n+1,0);
         for(int i=0;i<=n;i++)
         parent[i] = i;
    }

    int find_par(int node)
    {
        if(node==parent[node]) return node;

       return parent[node] = find_par(parent[node]);
    }

    void reset_node(int node)
    {
        parent[node] = node;
    }

   void union_find(int node1,int node2)
    {
          int ultimate_par1 = find_par(node1);
          int ultimate_par2 = find_par(node2);

          if(ultimate_par1 == ultimate_par2)
          {
             return ;
          }

          if(rank[ultimate_par1] > rank[ultimate_par2])
          {
                parent[ultimate_par2] = ultimate_par1; 

          }
          else if(rank[ultimate_par1] < rank[ultimate_par2])
          {
                parent[ultimate_par1] = ultimate_par2; 
          }
          else //  ranks are equal
          {
                parent[ultimate_par1] = ultimate_par2;
                rank[ultimate_par2]++;
          }

    }

};
class Solution {
public:
static bool cmp(vector<int>&a,vector<int>&b)
{
    if(a[2]==b[2]) 
    return a[0]<b[0]; 
    return a[2] < b[2];
}
    vector<int> findAllPeople(int n, vector<vector<int>>& m, int firstPerson) {
    vector<int>ans;
    sort(m.begin(),m.end(),cmp);
    DSU dsu(n);
    dsu.union_find(0,firstPerson);
    

    for(int i=0;i<m.size();)
    {
        int time = m[i][2];
        vector<int>people;
        while(i<m.size() && m[i][2]==time)
        {
            dsu.union_find(m[i][0],m[i][1]);
            people.push_back(m[i][0]);
            people.push_back(m[i][1]);
            i++;
        }

        for(int j=0;j<people.size();j++)
        {
            if(dsu.find_par(people[j]) != dsu.find_par(0)) 
            {
               // break it
               dsu.reset_node(people[j]);
            }
            // if they have the same parent it means they know the secret 

        }
    }
   
   // now all the nodes which are now connected with 0 they all know the secret so return them. 

    for(int i=0;i<n;i++)
    {
        if(dsu.find_par(i) == dsu.find_par(0)) 
        ans.push_back(i);
    }

    return ans ;


    }
};