#include<bits/stdc++.h>

using namespace std;


int equalPartition(int N, int arr[])
    {
        // code here
           int sum = 0;
        for(int i=0; i<N; i++){
            sum+=arr[i];
        }
        if(sum%2 != 0){
            return 0;
        }
        bool dp[N+1][sum+1];
        for(int i=0; i<=sum; i++){
            dp[0][i] = false;
        }
        for(int i=0; i<=N; i++){
            dp[i][0] = true;
        }
        for(int i=1; i<=N; i++){
            for(int j=1; j<=sum; j++){
                if(arr[i-1] <= j){
                    dp[i][j] = (dp[i-1][j] or dp[i-1][j-arr[i-1]]);
                }
                else{
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
        if(dp[N][sum/2] == true){
            return 1;
        }
        return 0;
    }

    int main()
{
    int n;
    cin >> n;

    int arr[n];

    for (int i = 0; i < n; i++)
        cin >> arr[i];

    int res = equalPartition(n,arr);

    if(res==1)
    cout<<"YES"<<endl;
    else
    cout<<"NO"<<endl;

    return 0;
}