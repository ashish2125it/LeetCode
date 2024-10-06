class Solution {
public:
    bool areSentencesSimilar(string s1, string s2) {
     int n1 = s1.size(),n2 = s2.size();
     deque<string>dq1,dq2;
     int i=0,j=0;
     while(i<n1)
     {
         int j=i;
         string temp = "";
         while(j<n1 && s1[j]!=' ')
         {
             temp += s1[j++];
         }
         dq1.push_back(temp);
          i=j+1;
     }
     i=0;
     while(i<n2)
     {
         int j=i;
         string temp = "";
         while(j<n2 && s2[j]!=' ')
         {
             temp += s2[j++];
         }
         dq2.push_back(temp);
          i=j+1;
     }

     while(!dq1.empty() && !dq2.empty())
     {
         if(dq1.front()!=dq2.front()) break;
         dq1.pop_front();
         dq2.pop_front();
     }
      while(!dq1.empty() && !dq2.empty())
     {
         if(dq1.back()!=dq2.back()) break;
         dq1.pop_back();
         dq2.pop_back();
     }

     return (dq1.empty() || dq2.empty()) ;
     


    }
};