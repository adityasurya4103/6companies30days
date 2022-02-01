#include <bits/stdc++.h>
using namespace std;

void dfs(int i, int j, vector<vector<int>> &grid ,int &count){
       int n = grid.size();
       int m = grid[0].size();
       if(i < 0 || j < 0) return;
       if(i >= n || j >= m) return;
       if(grid[i][j] != 1) return;
       count++;
       
               grid[i][j]=0;
       
                dfs(i+1,j,grid ,count);
                dfs(i,j+1,grid ,count);
                dfs(i-1,j,grid ,count);
                dfs(i,j-1,grid ,count);
                dfs(i+1,j+1,grid ,count);
                dfs(i+1,j-1,grid ,count);
                dfs(i-1,j+1,grid ,count);
                dfs(i-1,j-1,grid ,count);
                
}
   
   int findMaxArea(vector<vector<int>>& grid , int &count) {
       int r = grid.size();
       int c = grid[0].size();
       int Max = 0;
       for(int i = 0; i < r ; ++i){
           for(int j = 0; j < c; ++j){
               count=0;
               if(grid[i][j] == 1){
                   dfs(i,j,grid,count);
                   Max = max(count, Max);
               }
           }
       }
       return Max;
   }

int main()
{
    int m,n;
    cin >>m>>n;

    vector<vector<int>>grid(m ,vector<int>(n, -1));

    for (int i = 0; i < m; i++){
        for(int j=0; j<n; j++){
            cin>>grid[i][j];
        }
    }
    int count =1;
    int res = findMaxArea(grid , count);

    cout<<res<<endl;

    return 0;
}
