#include <bits/stdc++.h>

using namespace std;

int doOverlap(int L1[], int R1[], int L2[], int R2[])
{
    // code here
    if (L1[0] > R2[0] || L2[0] > R1[0])
        return false;

    if (L1[1] < R2[1] || L2[1] < R1[1])
        return false;

    return 1;
}

int main()
{
    int L1[2], R1[2], L2[2], R2[2];

    cin >> L1[0] >> L1[1] >> R1[0] >> R1[1] >> L2[0] >> L2[1] >> R2[0] >> R2[1];

    int ans = doOverlap(L1, R1, L2, R2);

    cout << ans << endl;
}