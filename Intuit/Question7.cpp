#include <bits/stdc++.h>

using namespace std;

  int shipWithinDays(vector<int>& weights, int days) {
          int sum = 0;
        int maxWeight = 0;
        for (auto& w : weights) {
            sum += w;
            maxWeight = max(w, maxWeight);
        }
        int minNeed = maxWeight, maxNeed = sum;
        while (minNeed < maxNeed) {
            int mid = (minNeed + maxNeed) / 2;
            int ship = 0, load = 0;
            for (auto& w : weights) {
    
                if (mid - load >= w) {
                    load += w;
                } else {
                    
                    ship++;
                   
                    if (ship == days) {
                        break;
                    }
                    load = w;
                }
            }
  
            if (ship < days) {
                maxNeed = mid;
            } else {
                
                minNeed = mid + 1;
            }
        }
        return minNeed;
    }


int main()
{
    int n;
    cin >> n;

    vector<int> a(n);

    for (int i = 0; i < n; i++)
        cin >> a[i];

    int days;
    cin >> days;

    int res = shipWithinDays(a,days);

    cout << res << endl;

    return 0;
}