#include <bits/stdc++.h>
using namespace std;

class Solution{
    public:
    // arr[] : int input array of integers
    // k : the quadruple sum required
    vector<vector<int> > fourSum(vector<int> &arr, int k) {
        int N = arr.size();
        vector<vector<int>> res;
        sort(arr.begin(), arr.end());
        
        for(int i = 0; i < N-1; i++) {
            for(int j = i + 1; j < N; j++) {
                int X = k - (arr[i] + arr[j]);
                int lo = j + 1, hi = N-1;
                
                while(lo < hi) {
                    if(arr[lo] + arr[hi] < X)
                        lo++;
                    else if(arr[lo] + arr[hi] > X)
                        hi--;
                    else { 
                        vector<int> temp = {arr[i], arr[j], arr[lo], arr[hi]};
                        res.push_back(temp);

                        while(lo < hi && arr[lo] == temp[2]) lo++;
                        while(lo < hi && arr[hi] == temp[3]) hi--;
                    }
                }
                while(j + 1 < N && arr[j+1] == arr[j]) j++;
            }
            while(i + 1 < N-1 && arr[i+1] == arr[i]) i++;
        }
        return res;
      
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k, i;
        cin >> n >> k;
        vector<int> a(n);
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        vector<vector<int> > ans = ob.fourSum(a, k);
        for (auto &v : ans) {
            for (int &u : v) {
                cout << u << " ";
            }
            cout << "$";
        }
        if (ans.empty()) {
            cout << -1;
        }
        cout << "\n";
    }
    return 0;
}  