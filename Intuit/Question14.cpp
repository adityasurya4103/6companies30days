#include <bits/stdc++.h>

using namespace std;

 int maxDistance(vector<vector<int>>& grid) {
        queue<pair<int,pair<int,int>>> q;
        int n = grid.size();
        int zerocount = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j] == 1) q.push({0,{i,j}});
                else{
                    zerocount++;
                    grid[i][j] = INT_MAX;
                }
            }
        }
        
        if(q.empty() || zerocount == 0) return -1;
        int arr[5] = {0,1,0,-1,0};
        
        int ans=0;
        
        while(!q.empty()){
            auto top = q.front(); q.pop();
            int curr_dist = top.first;
            int x = top.second.first;
            int y = top.second.second;
            
            for(int i=0;i<4;i++){
                int xnew = x+arr[i];
                int ynew = y+arr[i+1];
                
                if(xnew>=0 && xnew<n && ynew>=0 && ynew<n && grid[xnew][ynew]>curr_dist+1){
                    grid[xnew][ynew]=curr_dist+1;
                    q.push({curr_dist+1,{xnew,ynew}});
                    ans = max(ans,grid[xnew][ynew]);
                }
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

    int res = maxDistance(v);

    cout<<res<<endl;

    return 0;
}


