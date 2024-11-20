class Solution {
public:
int check(int low,int high,vector<vector<int>>&suff,int a,int b,int c)
{
    int ans = -1;
    while(low<=high)
    {
        int mid = (low+high)/2;
        if(suff[mid][0]>=a && suff[mid][1]>=b && suff[mid][2]>=c) 
        {
            ans = mid;
            low = mid+1;
        }
        else
        high =  mid-1;
    }
    return ans;
}
    int takeCharacters(string s, int k) {
    int n = s.length();
    if(k==0) return 0;
    if(n==1 || n==2) 
    {
        return -1;
    }
    vector<vector<int>>suff(n,vector<int>(3,0));

    if(s[n-1]=='a') suff[n-1][0] = 1;
    else if(s[n-1]=='b') suff[n-1][1] = 1;
    else
    suff[n-1][2]  = 1 ;

    for(int i=n-2;i>=0;i--)
    {
        suff[i] = suff[i+1];
        if(s[i]=='a') suff[i][0]++;
        else if(s[i]=='b') suff[i][1]++;
        else
        suff[i][2]++;
    }

    int a= 0,b=0,c=0;
    int ans = INT_MAX;
    for(int i=0;i<n-1;i++)
    {
        if(s[i]=='a') a++;
        else if(s[i]=='b') b++;
        else c++;

        if(a>=k && b>=k && c>=k) 
        ans = min(ans,i+1);

        int rem_a = k-a,rem_b = k-b, rem_c = k-c;
        int index = check(i+1,n-1,suff,rem_a,rem_b,rem_c);
        if(index==-1)
        {
            continue;
        }
        ans = min(ans,i+1+(n-1)-index+1);
    }
    int x = check(0,n-1,suff,k,k,k);
    if(x!=-1)
    ans = min(ans,(n-1)-x+1);
    if(ans==INT_MAX) return -1;
    return ans;

    }
};