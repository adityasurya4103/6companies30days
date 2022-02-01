#include <bits/stdc++.h>

using namespace std;

int minDifference(int arr[], int n)
{
    int range = 0;
    for (int i = 0; i < n; i++)
    {
        range += arr[i];
    }
    bool dp[n + 1][range + 1];

    for (int i = 0; i < n + 1; i++)
    {
        for (int j = 0; j < range + 1; j++)
        {
            if (i == 0)
                dp[i][j] = false;
            if (j == 0)
                dp[i][j] = true;
        }
    }
   
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= range; j++)
        {
            if (arr[i - 1] <= j)
            {
                dp[i][j] = dp[i - 1][j - arr[i - 1]] || dp[i - 1][j];
            }
            else
            {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }
   
    int ans = INT_MAX;
    for (int i = 0; i <= range / 2; i++)
    {
        if (dp[n][i] == true && ans > abs(i - (range - i)))
        {
            ans = abs(i - (range - i));
        }
    }
    return ans;
}

int main()
{
    int n;
    cin >> n;

    int arr[n];

    for (int i = 0; i < n; i++)
        cin >> arr[i];

    int res = minDifference(arr, n);

    cout << res << endl;

    return 0;
}