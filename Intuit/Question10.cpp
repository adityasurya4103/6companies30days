#include <bits/stdc++.h>

using namespace std;

    void dfs(vector<vector<int>>& isConnected, int i,int j){
        isConnected[i][j] = 0;
        for(int x=0;x<isConnected.size();x++){
            if(isConnected[j][x]==1){dfs(isConnected,j,x);}
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int maxp=0;
        vector<int> vis(isConnected[0].size(),0);
        for(int i=0;i<isConnected.size();i++){
            for(auto j=0;j<isConnected[0].size();j++){
                if(isConnected[i][j]==1){
                    maxp++;
                    dfs(isConnected,i,j);
                }
            }
        }
        return maxp;
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

    int res = findCircleNum(v);

     cout<<res<<endl;

    return 0;
}   

