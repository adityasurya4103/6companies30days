#include <bits/stdc++.h>

using namespace std;

string matrixChainOrder(int arr[], int n)
{
    // code here
    map<pair<int, int>, string> mp;
    int dp[n - 1][n - 1];

    for (int i = 0, j = 0; j < n - 1; ++j)
    {
        int r = i, c = j, len = n - 1 - j;
        while (len--)
        {
            if (j == 0)
            {
                dp[r][c] = 0;

                string str = "";
                char ch = 'A' + (n - 1 - len - 1);
                str = str + ch;
                mp[make_pair(r, c)] = str;
                r++;
                c++;
            }
            else if (j == 1)
            {
                dp[r][c] = arr[r] * arr[c] * arr[c + 1];
                mp[make_pair(r, c)] = '(' + mp[make_pair(r, c - 1)] + mp[make_pair(r + 1, c)] + ')';
                r++, c++;
            }
            else
            {
                int right, down;
                dp[r][c] = INT_MAX;
                for (right = r, down = r + 1; right <= c && down <= c; right++, down++)
                {

                    int operations = dp[r][right] + dp[down][c] + arr[r] * arr[down] * arr[c + 1];

                    if (dp[r][c] > operations)
                    {
                        dp[r][c] = operations;
                        mp[make_pair(r, c)] = '(' + mp[make_pair(r, right)] + mp[make_pair(down, c)] + ')';
                    }
                }

                r++, c++;
            }
        }
    }

    return mp[make_pair(0, n - 2)];
}

int main()
{
    int N;
    cin >> N;

    int arr[N];
    for (int i = 0; i < N; i++)
    {
        cin >> arr[i];
    }
    string res;
    res = matrixChainOrder(arr , N);

   cout<<res<<endl;

    return 0;
}