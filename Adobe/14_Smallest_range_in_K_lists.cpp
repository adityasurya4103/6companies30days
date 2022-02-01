#include <bits/stdc++.h>
using namespace std;
#define N 1000

class Solution
{
public:
    pair<int, int> findSmallestRange(int KSortedArray[][N], int n, int k)
    {
        set<pair<int, pair<int, int>>> s;

        pair<int, int> res{0, INT_MAX};

        for (size_t i = 0; i < k; ++i)
        {
            s.insert({KSortedArray[i][0], {i, 0}});
        }

        while (!s.empty())
        {
            int minVal = s.begin()->first;
            int maxVal = s.rbegin()->first;
            if (res.second - res.first > maxVal - minVal)
            {
                res.first = minVal;
                res.second = maxVal;
            }

            int r = s.begin()->second.first;
            int c = s.begin()->second.second;
            s.erase(s.begin());
            if (c + 1 == n)
                break;
            s.insert({KSortedArray[r][c + 1], {r, c + 1}});
        }
        return res;
    }
};

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        int arr[N][N];
        pair<int, int> rangee;
        for (int i = 0; i < k; i++)
            for (int j = 0; j < n; j++)
                cin >> arr[i][j];
        Solution obj;
        rangee = obj.findSmallestRange(arr, n, k);
        cout << rangee.first << " " << rangee.second << "\n";
    }
    return 0;
}
