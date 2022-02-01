#include <bits/stdc++.h>

using namespace std;

class Solution {

public:

    int maxCoins(vector<int>&A,int n)

    {

	    vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));

	    return recursion(A, 0, n - 1, dp);

    }

    int recursion(vector<int>& A, int start, int end, vector<vector<int>>& dp){

        if(start > end) return dp[start][end] = 0;

        if(start == end) return dp[start][end] = A[start];

        if(dp[start][end] != -1) return dp[start][end];

        int first = A[start] + min(recursion(A, start + 2, end, dp), recursion(A, start + 1, end - 1,dp));

        int second = A[end] + min(recursion(A, start + 1, end - 1,dp), recursion(A, start, end - 2,dp));

        return dp[start][end] = max(first, second);

    }

};

int main() {

    int t;

    cin >> t;

    while (t--) {

        int N;

        cin >> N;

        vector<int>A(N);

        for (int i = 0; i < N; i++) {

            cin >> A[i];

        }

        Solution ob;

        cout << ob.maxCoins(A, N) << "\n";

    }

    return 0;

}
