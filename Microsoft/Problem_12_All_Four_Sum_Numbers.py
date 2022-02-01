class Solution:
    def fourSum(self, arr, k):
        n = len(arr)
        ans=[]
        arr.sort()
        if n<4:
            return ans
        for i in range(n-3):
            if (a[i] > 0 and a[i] > k):
                break
            if (i > 0 and a[i] == a[i - 1]):
                continue
            for j in range(i+1,n-2):
                if (j > i + 1 and a[j] == a[j - 1]):
                    continue
                c=j+1
                d= n-1
                while c<d:
                    t1 = c
                    t2= d
                    sum= arr[i]+arr[j]+arr[c]+arr[d]
                    if sum==k:
                        ans.append([arr[i],arr[j],arr[c],arr[d]])
                        while c<d and arr[c]==arr[t1]:
                            c+=1
                        while c<d and arr[d]==arr[t2]:
                            d-=1
                        
                    elif sum<k:
                        c+=1
                    else:
                        d-=1
                
                    
        return ans
