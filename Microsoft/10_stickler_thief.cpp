#include <bits/stdc++.h>

using namespace std;

int FindMaxSum(int arr[], int n)
{
    // Your code here
    int incl = arr[0];
    int excl = 0;
    int new_excl;
    for (int i = 1; i < n; i++)
    {
        new_excl = (incl > excl) ? incl : excl;
        incl = excl + arr[i];
        excl = new_excl;
    }
    return ((incl > excl) ? incl : excl);
}

int main()
{
    int n;
    cin >> n;

    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    int result = FindMaxSum(arr, n);

    cout << result << endl;

    return 0;
}
