#include <bits/stdc++.h>

using namespace std;


class Solution{

public:

    int equalPartition(int N, int arr[])

    {

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

};

int main(){

    int t;

    cin>>t;

    while(t--){

        int N;

        cin>>N;

        int arr[N];

        for(int i = 0;i < N;i++)

            cin>>arr[i];

        

        Solution ob;

        if(ob.equalPartition(N, arr))

            cout<<"YES\n";

        else

            cout<<"NO\n";

    }

    return 0;

}
