#include <bits/stdc++.h>

using namespace std;

	int minDifference(int arr[], int n)  { 
	    int sum=0;
	    
	    for(int i=0;i<n;i++)
	    {
	        sum+= arr[i];
	    }
	    bool dp[n+1][sum+1];
	    
	    for(int i=0;i<=n;i++)
	    {
	        for(int j=0;j<=sum;j++)
	        {
	            if(i==0)
	            {
	                dp[i][j]=false;
	            }
	            
	            if(j==0)
	            {
	                dp[i][j] = true;
	            }
	        }
	    }
	    
	    for(int i=1;i<=n;i++)
	    {
	        for(int j=1;j<=sum;j++)
	        {
	            if(arr[i-1]<=j)
	            {
	                dp[i][j] = dp[i-1][j] || dp[i-1][j-arr[i-1]];
	            }
	            else
	            {
	                dp[i][j] = dp[i-1][j];
	            }
	        }
	    }
	    
	    int ans = INT_MAX;
	    
	    for(int i=0;i<=sum/2;i++)
	    {
	        if(dp[n][i]==true && ans>abs(i-(sum-i)))
	        {
	            ans  = abs(i-(sum-i));
	        }
	    }
	    return ans;
	} 


    int main(){
        int n;
        cin>>n;

        int arr[n];
        for(int i=0 ; i<n ;i++)
         cin>>arr[i];

        int result = minDifference(arr, n);

        cout<<result<<endl;

        return 0; 
    }
