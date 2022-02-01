class Solution:
    
    #Function to calculate the span of stockâ€™s price for all n days.
    def calculateSpan(self,a,n):
        ans=[0]*n
        ans[0]=1
        for i in range(1,n):
            ans[i]=1
            j=i-1
            while j>=0:
                if a[j]<=a[i]:
                    ans[i]+=ans[j]
                else:
                    break
                j-=ans[j]
        return ans
