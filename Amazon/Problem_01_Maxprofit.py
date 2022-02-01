#User function Template for python3

class Solution:
    def maxProfit(self, K, N, A):
        
        # code here
        if not len(A):
            return 0
        
        profit=[[0 for d in A] for t in range(K+1)]
        # print(profit)
        
        for t in range(1,K+1):
            maxSoFar=float('-inf')
            
            for d in range(1,N):
                maxSoFar=max(maxSoFar,profit[t-1][d-1]-A[d-1])
                profit[t][d]=max(profit[t][d-1],A[d]+maxSoFar)
                
        return profit[-1][-1]
            

#{ 
#  Driver Code Starts
#Initial Template for Python 3

if __name__ == '__main__':
    t = int(input())
    for _ in range(t):
        K = int(input())
        N = int(input())
        A = input().split()
        for i in range(N):
            A[i] = int(A[i])
        
        ob = Solution()
        print(ob.maxProfit(K, N, A))
# } Driver Code Ends
