#include <bits/stdc++.h>

using namespace std;

long long numOfWays(int n, int x)
{
    long long dp[n + 1];
    memset(dp, 0, sizeof(dp));

    dp[0] = dp[1] = 1;

    int maxLimit = pow(n, 1.0 / x);

    for (int i = 2; i <= maxLimit; i++)
    {
        int curr = pow(i, x);

        for (int j = n; j >= curr; j--)
        {
            dp[j] += dp[j - curr];
        }
    }

    return dp[n];
}

int main()
{
    int n;
    cin >> n;

    int x;
    cin >> x;

    long long res = numOfWays(n, x);

    cout << res << endl;

    return 0;
}