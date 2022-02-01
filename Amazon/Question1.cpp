#include <bits/stdc++.h>

using namespace std;

int maxProfit(int K, int N, int A[])
{
    // code here
    int dp[K + 1][N];
    memset(dp, 0, sizeof(dp));
    for (int i = 1; i <= K; i++)
    {
        int max_num = INT_MIN;
        for (int j = 1; j < N; j++)
        {
            if ((dp[i - 1][j - 1] - A[j - 1]) > max_num)
            {
                max_num = dp[i - 1][j - 1] - A[j - 1];
            }

            if ((max_num + A[j]) > dp[i][j - 1])
                dp[i][j] = max_num + A[j];
            else
                dp[i][j] = dp[i][j - 1];
        }
    }

    return dp[K][N - 1];
}

int main()
{
    int K, N;
    cin >> K >> N;

    int arr[N];
    for (int i = 0; i < N; i++)
        cin >> arr[i];

    int result = maxProfit(K, N, arr);

    cout << result << endl;

    return 0;
}