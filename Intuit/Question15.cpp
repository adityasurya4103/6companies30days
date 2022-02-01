#include <bits/stdc++.h>

using namespace std;

 int minEatingSpeed(vector<int>& piles, int H) {
        int low = 1, high = 1000000000, k = 0;
        while (low <= high) {
            k = (low + high) / 2;
            int h = 0;
            for (int i = 0; i < piles.size(); i ++) 
                h += ceil(1.0 * piles[i] / k);
            if (h > H)
                low = k + 1;
            else
                high = k - 1;
        }
        return low;
    }


int main()
{
    int n;
    cin >> n;
   
    vector<int>v(n);
    for (int i = 0; i < n; i++)
    {
        cin>>v[i];
    }

    int h;
    cin>>h;

    int res = minEatingSpeed(v,h);

    cout<<res<<endl;

    return 0;
}
