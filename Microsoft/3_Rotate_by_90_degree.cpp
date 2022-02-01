#include<bits/stdc++.h>
using namespace std;

void rotate(vector<vector<int> >& matrix)
{
    // Your code goes here
     for(auto &i: matrix)
   {
       reverse(i.begin(),i.end());
   }
   for(int i=0; i<matrix.size(); i++)
   {
       for(int j=i; j<matrix[i].size(); j++)
       {
           swap(matrix[i][j],matrix[j][i]);
       }
   }
}

int main()
{
        int n;
        cin>>n; 
        vector<vector<int> > matrix(n);
        for(int i=0; i<n; i++)
        {
            matrix[i].resize(n);
            for(int j=0; j<n; j++)
                cin>>matrix[i][j]; 
        }
        rotate(matrix);
        for (int i = 0; i < n; ++i)
        {
            for(int j=0; j<n; j++)
                cout<<matrix[i][j]<<" ";
            cout<<"\n";
        }
    
    return 0;
}
