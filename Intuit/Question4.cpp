#include <bits/stdc++.h>

using namespace std;

void helper(string s, string &res, int k, int ind)
{
    if (k == 0)
        return;
    if (ind == s.length())
        return;
    int chk = s[ind] - '0';
    int j = -1;
    for (int i = ind + 1; i < s.length(); i++)
    {
        if (chk < s[i] - '0')
        {
            chk = s[i] - '0';
        }
    }
    if (chk != s[ind] - '0')
    {
        k--;
    }
    for (int i = s.length() - 1; i >= ind; i--)
    {
        if (s[i] - '0' == chk)
        {
            swap(s[ind], s[i]);
            res = max(res, s);
            helper(s, res, k, ind + 1);
            swap(s[ind], s[i]);
        }
    }
}
string findMaximumNum(string str, int k)
{
    // code here.
    string res = str;
    helper(str, res, k, 0);
    return res;
}

int main()
{
    int t;
    cin >> t;

    string s;
    cin >> s;

    string res = findMaximumNum(s, t);

    cout << res << endl;

    return 0;
}