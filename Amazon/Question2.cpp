#include <bits/stdc++.h>

using namespace std;

int longestMountain(vector<int> &arr)
{
    int count, j, mx = 0, n = arr.size();
    bool flag;
    for (int i = 1; i < n; i++)
    {
        j = i;
        count = 1;
        flag = false;

        //increasing sequence
        while (j < n && arr[j] > arr[j - 1])
        {
            count++;
            j++;
        }

        //decreasing sequence
        while (i != j && j < n && arr[j] < arr[j - 1])
        {
            count++;
            j++;
            flag = true;
        }

        //length is max or not
        if (i != j && flag && count >= 3)
        {
            mx = max(mx, count);
            j--;
        }

        i = j;
    }
    return mx;
}

int main()
{
    int N;
    cin >> N;

    vector<int> arr(N);
    for (int i = 0; i < N; i++)
    {
        cin >> arr[i];
    }

    int result = longestMountain(arr);

    cout << result << endl;

    return 0;
}