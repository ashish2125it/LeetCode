class Solution {
public:
    long long countInterestingSubarrays(vector<int>& nums, int mod, int k) {
        vector<int>prefix(nums.size(), 0); 
        long long count =0 , ans =0;  
        int n = nums.size();

        for(int i =0; i<nums.size(); i++){
             if( nums[i] %mod == k) count++; 
             prefix[i] = count%mod; 
        }

unordered_map< int ,int > store; 
store[0] =1; 
for(auto it : prefix){
     int val = (it-k+mod)%mod;
     if( store.count(val)){
          ans += store[val]; 
     }
     store[it]++;  
}
    return ans;     
    }
};