#include <bits/stdc++.h>

using namespace std;

string decodedString(string s)
{
    // code here
    int currNo = 0;
    string currString = "";
    int prevNo;
    string prevString;
    stack<string> stringstack;
    stack<int> numstack;
    for (int i = 0; i < s.size(); i++)
    {
        if (isdigit(s[i]))
            currNo = currNo * 10 + (s[i] - '0');
        if (isalpha(s[i]))
            currString += s[i];
        if (s[i] == '[')
        {
            stringstack.push(currString);
            numstack.push(currNo);
            currNo = 0;
            currString = "";
        }
        if (s[i] == ']')
        {
            prevNo = numstack.top();
            numstack.pop();
            prevString = stringstack.top();
            stringstack.pop();

            while (prevNo--)
            {
                prevString += currString;
            }
            currString = prevString;
        }
    }
    return currString;
}

int main()
{
    string s;
    cin >> s;

    string res = decodedString(s);

    cout << res << endl;

    return 0;
}