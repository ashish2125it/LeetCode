class Solution {
public:
    vector<int> getFinalState(vector<int>& nums, int k, int m) {
    int n = nums.size();
     priority_queue<std::pair<int, int>, vector<std::pair<int, int>>, 
                        decltype([](const pair<int, int>& a, const pair<int, int>& b) {
                            if (a.first == b.first)
                                return a.second > b.second; // If first values are equal, compare second
                            return a.first > b.first;      // Else, compare first values
                        })> pq;

    for(int i=0;i<n;i++) pq.push({nums[i],i});

     while(k)
     {
    int val = pq.top().first;
    int ind = pq.top().second;
    pq.pop();
    int new_val = val*m;
    nums[ind] = new_val;
    pq.push({new_val,ind});
    k--;
     }
     return nums;
    }
};