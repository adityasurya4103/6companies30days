#include <bits/stdc++.h>

using namespace std;

    long long squaresInChessBoard(long long N) {
        // code here
        long long res;
        
        res = N*(N+1)*(2*N+1)/6;
        
        return res;
    }

    int main(){
        long long n;
        cin>>n;

        long long ans = squaresInChessBoard(n);

        cout<<ans<<endl;

        return 0;
    }