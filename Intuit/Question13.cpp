#include <bits/stdc++.h>

using namespace std;

int minSwaps(vector<vector<int>>& grid){
        int n = grid.size();
        int ans = 0;
        vector<int> t;
        
        for(int i=0;i<n;i++){
            int zero = 0;
            for(int j=n-1;j>=0;j--){
                if(grid[i][j]) break;
                zero++;
            }
            t.push_back(zero);
        }
        
 
        for(int i=0;i<n;i++){
            
            int curr = i;
            int req = n - 1 - i; 
            
            while(curr < n and t[curr] < req) curr++;
            
            if(curr == n) return -1;
            
            ans += curr - i;
            
            while(curr > 0){
                t[curr] = t[curr - 1];
                curr--;
            }
            
        }
        
        return ans;
    }


int main()
{
    int n;
    cin >> n;
    int m;
    cin>>m;
    vector<vector<int>> v(n, vector<int>(m, 0));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> v[i][j];
        }
    }

    int res = minSwaps(v);

    cout<<res<<endl;

    return 0;
}


