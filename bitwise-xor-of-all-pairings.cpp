class Solution {
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
    int n1 =nums1.size(),n2= nums2.size();

    int x =0,y =0;
    for(int i=0;i<n1;i++)
    x = x^nums1[i];

     for(int i=0;i<n2;i++)
    y = y^nums2[i];

    if(n1%2==0)
     y=0;
    
    if(n2%2==0)
    x =0;

    return x^y;
    
    }
};