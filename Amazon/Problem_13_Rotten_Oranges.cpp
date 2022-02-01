class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int r=grid.size();
        int c=grid[0].size();
        queue<pair<int,int>>q;
        int count_unrot=0;
        for(int i=0;i<r;i++)
        {
            for(int j=0;j<c;j++)
            {
                if(grid[i][j]==2)
                    q.push({i,j});
                if(grid[i][j]==1)
                    count_unrot++;
            }
        }
        if(!count_unrot)
            return 0;
        q.push({-1,-1});
        int ans=0;
        while(!q.empty())
        {
            pair<int,int>curr_cell=q.front();
            q.pop();
            int i=curr_cell.first,j=curr_cell.second;
            if(i==-1&&j==-1)
            {
             if(!q.empty())
             {q.push({-1,-1});
              ans++;
             }
             continue;
            }
            //down
            if(i+1<r&&grid[i+1][j]==1)
            {
                grid[i+1][j]=2;
                count_unrot--;
                q.push({i+1,j});
            }
            //left
            if(j-1>=0&&grid[i][j-1]==1)
            {
                grid[i][j-1]=2;
                count_unrot--;
                q.push({i,j-1});
            }
            //right
            if(j+1<c&&grid[i][j+1]==1)
            {
                grid[i][j+1]=2;
                count_unrot--;
                q.push({i,j+1});
            }
            //up
            if(i-1>=0&&grid[i-1][j]==1)
            {
                grid[i-1][j]=2;
                count_unrot--;
                q.push({i-1,j});
            }
               
        }
       if(count_unrot>0)
           return -1;
        return ans;
    }
}
