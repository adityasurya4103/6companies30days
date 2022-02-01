class Solution:
    
        
    #Function to find list of all words possible by pressing given numbers.
    def possibleWords(self,a,N):
        mp={}
        mp[2]="abc";
        mp[3]="def";
        mp[4]="ghi";
        mp[5]="jkl";
        mp[6]="mno";
        mp[7]="pqrs";
        mp[8]="tuv";
        mp[9]="wxyz";
        def ans(a,N,cur,s="",res=[]):
            if cur>=N:
                res.append(s)
                return res
            temp = mp[a[cur]]
            for i in range(0,len(temp)):
                ans(a,N,cur+1,s+temp[i],res)
            return res
        return ans(a,N,0)
