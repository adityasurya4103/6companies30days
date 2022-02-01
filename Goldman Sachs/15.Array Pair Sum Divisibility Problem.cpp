#include <bits/stdc++.h>

using namespace std;

bool canPair(vector<int> nums, int k)
{
    // Code here.
    unordered_map<int, int> mp;

    for (int i = 0; i < nums.size(); i++)
    {
        mp[nums[i] % k]++;
    }
    if (mp[0] % 2 == 1)
        return false;
    for (int i = 0; i < nums.size(); i++)
    {
        int x = nums[i] % k;
        int y;
        if (x == 0)
            y = 0;
        else
            y = k - x;
        if (mp[y] != mp[x])
            return false;
    }
    return true;
}

int main()
{
    int n;
    cin >> n;

    int k;
    cin >> k;

    vector<int> nums(n);

    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }

    bool res = canPair(nums, k);

    if (res)
        cout << "True" << endl;
    else
        cout << "False" << endl;

    return 0;
}