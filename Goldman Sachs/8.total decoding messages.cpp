#include <bits/stdc++.h>

using namespace std;

int CountWays(string str)
{
    // Code here
    int n = str.length();

    int count = 0;
    int dp[n + 1];

    dp[0] = 1;

    if (str[0] == '0')
        return 0;
    if (n == 1)
        return 1;

    for (int i = 1; i < n; i++)
    {

        if (str[i - 1] == '0' and str[i] == '0')
        {
            dp[i] = 0;
        }
        else if (str[i - 1] == '0' and str[i] != '0')
        {
            dp[i] = dp[i - 1];
        }
        else if (str[i - 1] != '0' and str[i] == '0')
        {
            if (str[i - 1] == '1' or str[i - 1] == '2')
            {
                dp[i] = (i >= 2 ? dp[i - 2] : 1);
            }
            else
                dp[i] = 0;
        }
        else
        {

            if (str[i - 1] == '1' || (str[i - 1] == '2' && str[i] < '7'))
            {
                dp[i] = (dp[i - 1] + (i >= 2 ? dp[i - 2] : 1)) % 1000000007;
            }
            else
                dp[i] = dp[i - 1];
        }
    }

    return dp[n - 1];
}

int main(){
    string input;
    cin>>input;

    int res = CountWays(input);

    cout<<res<<endl;

    return 0;
}