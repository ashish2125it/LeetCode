class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        n1 = len(s)
        n2 = len(t)
        dict1 = {}
        dict2 = {}

        for i in range(0,n1):
            dict1[s[i]] = dict1.get(s[i], 0) + 1

        for i in range(0,n2):
            dict2[t[i]] = dict2.get(t[i], 0) + 1


        for key, value in dict1.items():
            if dict2.get(key,0)!=value:
                return False
         
          


        return True             


        