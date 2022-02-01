class Solution
{
    public:
    //Function to count number of ways to reach the nth stair 
    //when order does not matter.
    long long countWays(int m)
    {
        long long *dp=new long long[m+1]();
        dp[0]=1;
        dp[1]=1;
     
        for(int i=2;i<=m;i++)
        {
            dp[i]=min(dp[i-1],dp[i-2])+1;
        }
        return dp[m];
    }
};
