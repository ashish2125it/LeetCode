class Solution {
public:
    bool doesValidArrayExist(vector<int>& d) {
    
    int n = d.size();
    int x= 0;
    for(auto it:d)
    x = x^it;

    if(x==0) return 1;
    return 0; 
    }
};