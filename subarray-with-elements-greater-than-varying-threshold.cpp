class Solution {
vector<int> solve2(vector<int>&nums, int n) {
    stack<int>s;
    vector<int>ans(n,n);
    for(int i=n-1;i>=0;i--) {
        while(!s.empty() && nums[s.top()] >= nums[i])
            s.pop();

        if(s.size() > 0)
            ans[i] = s.top();

        s.push(i);
    }
    return ans;
}

vector<int> solve1(vector<int>&nums, int n) {
    stack<int>s;
    vector<int>ans(n,-1);
    for(int i=0;i<n;i++) {
        while(!s.empty() && nums[s.top()] >= nums[i])
            s.pop();

        if(s.size() > 0)
            ans[i] = s.top();

        s.push(i);
    }
    return ans;
}
public:
    int validSubarraySize(vector<int>& nums, int th) {
    int n = nums.size();
    vector<int>next = solve2(nums,n);
    vector<int>prev = solve1(nums,n);

    for(auto it:prev) cout<<it<<" ";
    cout<<endl;
    for(auto it:next) cout<<it<<" ";

    
    int max_len = -1;
    for(int i=0;i<n;i++)
    {
        
  int len = next[i] - prev[i] - 1; 
if (nums[i] > th / len) {
                return len;  
    }
    }

    return max_len;

    }
};