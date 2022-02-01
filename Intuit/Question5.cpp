#include <bits/stdc++.h>

using namespace std;

int splitArray(vector<int> &a, int m)
{
    int n = a.size();
    int sum = 0;
    for (auto t : a)
        sum += t;

    int l = a[0];
    int r = sum;

    for (int i = 1; i < a.size(); i++)
        l = max(l, a[i]);
    int ans = INT_MAX;
    while (l <= r)
    {
        int mid = l + (r - l) / 2;
        int t = 0;
        int c = 0;
        int s = 0;
        for (int i = 0; i < n; i++)
        {
            s += a[i];
            if (s > mid)
            {
                c++;
                s = a[i];
            }
        }
        if (s > 0)
            c++;
        if (c <= m)
        {

            ans = min(ans, mid);
            r = mid - 1;
        }
        else if (c > m)
            l = mid + 1;
    }
    return ans;
}

int main()
{
    int n;
    cin >> n;

    vector<int> a(n);

    for (int i = 0; i < n; i++)
        cin >> a[i];

    int m;
    cin >> m;

    int res = splitArray(a, m);

    cout << res << endl;

    return 0;
}