#include <bits/stdc++.h>

using namespace std;

 int numberOfBoomerangs(vector<vector<int>>& points) {
        int n = points.size();
if(n==1) return 0;

    int ans = 0;
    unordered_map<int,int> checkBoomerang; 
    
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(i==j) continue; 
            int x = (points[i][0] - points[j][0])*(points[i][0] - points[j][0]);
            int y = (points[i][1] - points[j][1])*(points[i][1] - points[j][1]);
            int distance = x + y;
            checkBoomerang[distance]++;
        }
    
        for(auto &it : checkBoomerang){
            int totalBoomerangs = it.second;  
            ans += totalBoomerangs*(totalBoomerangs-1); 
        }
        checkBoomerang.clear(); 
    }
    return ans;
    }

int main()
{
    int n;
    cin>>n;
     vector<vector<int>>v(n , vector<int>(2 ,0));
    for (int i = 0; i < n; i++){
        for(int j =0 ; j<2 ; j++){
            cin>>v[i][j];
        }
    }
    
    int res = numberOfBoomerangs(v);

    cout << res << endl;

    return 0;
}    