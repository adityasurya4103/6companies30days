#include <bits/stdc++.h>
using namespace std;

vector<int> calculateSpan(int price[], int n)
{
    stack<pair<int, int>> st;
    st.push({price[0], 1});
    vector<int> ans(n, 1);

    int i = 1;
    while (i < n)
    {
        int cur = price[i];
        int c = 0;
        while (!st.empty() && st.top().first <= cur)
        {
            c += st.top().second;
            st.pop();
        }
        ans[i] += c;
        st.push({cur, ans[i]});
        i++;
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

    vector<int> result = calculateSpan(arr, n);

    for (int i = 0; i < result.size(); ++i)
    {
        cout << result[i] << " ";
    }

    return 0;
}
