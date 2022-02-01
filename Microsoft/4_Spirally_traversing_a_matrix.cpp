#include <bits/stdc++.h>
using namespace std;

vector<int> spirallyTraverse(vector<vector<int>> matrix, int r, int c)
{
    // code here
    vector<int> ans;

    int row = matrix.size();
    int col = matrix[0].size();

    int count = 0;
    int total = row * col;

    int srow = 0;
    int scol = 0;
    int erow = row - 1;
    int ecol = col - 1;
    int i;
    while (count < total)
    {
        for (i = scol; i <= ecol && count < total; i++)
        {
            ans.push_back(matrix[srow][i]);
            count++;
        }
        srow++;

        for (i = srow; i <= erow && count < total; i++)
        {
            ans.push_back(matrix[i][ecol]);
            count++;
        }
        ecol--;

        for (i = ecol; i >= scol && count < total; i--)
        {
            ans.push_back(matrix[erow][i]);
            count++;
        }
        erow--;

        for (i = erow; i >= srow && count < total; i--)
        {
            ans.push_back(matrix[i][scol]);
            count++;
        }
        scol++;
    }
    return ans;
}

int main()
{
        int r,c;
        cin>>r>>c; 
        vector<vector<int> > matrix(r);
        for(int i=0; i<r; i++)
        {
            matrix[i].assign(c,0);
            for(int j=0; j<c; j++)
                cin>>matrix[i][j]; 
        }
        vector<int>res = spirallyTraverse(matrix , r, c);

        for (int i = 0; i < res.size() ; ++i)
        {
            cout<<res[i]<<" ";
        }
    
    return 0;
}
