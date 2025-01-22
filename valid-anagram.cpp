class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        desc1 = {}
        desc2 = {}
        n1 = len(s)
        n2 = len(t)
        if(n1!=n2):
            return False

        for i in range(0,n1):
            if(s[i] not in desc1):
                desc1[s[i]] = 1
            else:
                desc1[s[i]]+=1


        for i in range(0,n2):
            if(t[i] not in desc2):
                desc2[t[i]] = 1
            else:
                desc2[t[i]]+=1


        for key in desc1:
            if desc1[key] != desc2.get(key, 0):
                return False
        return True             


                
                         

        
        