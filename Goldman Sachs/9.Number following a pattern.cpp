#include <bits/stdc++.h>

using namespace std;

string printMinNumberForPattern(string S)
{
    // code here
    stack<int> s1;
    string res;

    int count = 1;

    for (int i = 0; i < S.length(); i++)
    {
        char ch = S[i];

        if (ch == 'D')
        {
            s1.push(count);
            count++;
        }
        else
        {
            s1.push(count);
            while (!s1.empty())
            {
                res += to_string(s1.top());
                s1.pop();
            }
            count++;
        }
    }
    s1.push(count);

    while (!s1.empty())
    {
        res += to_string(s1.top());
        s1.pop();
    }
    return res;
}

int main()
{
    string S;
    cin >> S;

    string res = printMinNumberForPattern(S);

    cout << res << endl;

    return 0;
}