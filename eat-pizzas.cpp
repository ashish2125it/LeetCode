#define ll long long
class Solution {
public:
    long long maxWeight(vector<int>& p) {
    ll ans = 0;
    int n = p.size();
    sort(p.begin(),p.end());
    int i = p.size()-1;
    int tot = n/4;
    int even =0,odd= 0;
    if(tot%2==0)
    {
        even = tot/2;
        odd=  (tot/2) ;
    }
    else
    {
        even = tot/2;
        odd=  (tot/2)+1 ;
    }

   
    while(odd)
    {
        ans += p[i];
        odd--;
        i--;
    } 
    i--;
    while(even)
    {
        ans += p[i];
        i= i-2;
        even--;
    }
    return ans;



    }
};