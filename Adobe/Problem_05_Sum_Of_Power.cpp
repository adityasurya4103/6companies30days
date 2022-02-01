#include <bits/stdc++.h>

using namespace std;


class Solution{

    public:

    long long int dp[1001][1001];

    long long int find(int i,int sum,int limit,int x,int n){

        if(i > limit+1) return 0;

       

        else if(sum > n) return 0;

        

        else if(dp[i][sum] != -1) return dp[i][sum];

        

        else if(sum == n)   return 1;

        

        long long int withPowSum = find(i+1,sum + pow(i,x),limit,x,n);            

        long long int withoutPowSum = find(i+1,sum,limit,x,n);

        return dp[i][sum] = withPowSum + withoutPowSum;

    }

    long long int numOfWays(int n, int x){

        int limit = pow(n,1.0/x);

        memset(dp,-1,sizeof dp);

        return find(1,0,limit,x,n);


    }

};


int main() {

    int t;

    cin >> t;

    while (t--) {

        int  n, x;

        cin >> n >> x;

        Solution ob;

        cout<<ob.numOfWays(n, x)<<endl;

    }

    return 0;

}
