class Solution {
public:
    int maximumSwap(int num) {
    string temp = to_string(num);
    int n = temp.size();
    for(int i=0;i<n;i++)
    {
        int maxi = 0;
        int index;
        for(int j=i+1;j<n;j++)
        {
           if((temp[j]-'0') > maxi) 
           {
            maxi = temp[j]-'0';
            index = j;
           }
        }

        if(maxi > (temp[i]-'0'))
        {
            swap(temp[i],temp[index]);
            return stoi(temp);
        }
    }

      return num;

    }
};