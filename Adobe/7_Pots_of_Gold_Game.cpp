#include <bits/stdc++.h>

using namespace std;

int solve(vector<int> &nums, vector<vector<int>> &dp, int s, int e)
{
    if (s > e)
        return dp[s][e] = 0;
    if (s == e)
        return dp[s][e] = nums[s];
    if (dp[s][e] != -1)
        return dp[s][e];

    int l = nums[s] + min(solve(nums, dp, s + 2, e), solve(nums, dp, s + 1, e - 1));
    int r = nums[e] + min(solve(nums, dp, s + 1, e - 1), solve(nums, dp, s, e - 2));

    return dp[s][e] = max(l, r);
}

int maxCoins(vector<int> &A, int n)
{
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
    return solve(A, dp, 0, n - 1);
}

int main()
{
    int n;
    cin >> n;

    vector<int> arr(n);

    for (int i = 0; i < n; i++)
        cin >> arr[i];

    int res = maxCoins(arr, n);

    cout << res << endl;

    return 0;
}