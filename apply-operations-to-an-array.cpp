class Solution {
public:
    vector<int> applyOperations(vector<int>& nums) {
        const int n=nums.size();
        for(int i=0; i<n-1; i++){
            if (nums[i]==nums[i+1]){
                nums[i]<<=1;
                nums[i+1]=0;
                i++;// 0 needs no operation
            }
        }
        int j=0;
        for(int i=0; i<n; i++){
            if (nums[i]>0) nums[j++]=nums[i];
        }
        fill(nums.begin()+j, nums.end(), 0);
        return nums;
    }
};