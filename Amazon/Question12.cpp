#include <bits/stdc++.h>

using namespace std;


    string colName(long long int n)
    {
        // your code here
        string temp = "";
        while (n > 0)
        {
            char ch = 'A' + (n - 1) % 26;
            temp = ch + temp;
            n = (n - 1) / 26;
        }
        return temp;
    }


int main()
{

    long long int n;
    cin >> n;

    cout << colName(n) << '\n';
}
