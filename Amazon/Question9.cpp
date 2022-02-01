#include <bits/stdc++.h>

using namespace std;

int isValid(vector<vector<int>> mat)
{
    int maxi = 15;
    int n = 9;

    //setting the matrix
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {

            int temp = mat[i][j] % maxi;
            if (temp)
            {
                mat[i][temp - 1] += maxi;
                if (mat[i][temp - 1] / maxi > 1)
                    return false;
            }
        }
    }

    //resetting the matrix
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            mat[i][j] = mat[i][j] % maxi;
        }
    }

    //setting the matrix
    for (int j = 0; j < n; j++)
    {
        for (int i = 0; i < n; i++)
        {

            int temp = mat[i][j] % maxi;
            if (temp)
            {
                mat[temp - 1][j] += maxi;
                if (mat[temp - 1][j] / maxi > 1)
                    return false;
            }
        }
    }
    //Resetting the matrix

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            mat[i][j] = mat[i][j] % maxi;
        }
    }

    //setting the matrix
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            int i1 = i / 3;
            int j1 = j / 3;
            int in;
            if (i1 == 0)
                in = j1;
            if (i1 == 1)
                in = 3 + j1;
            if (i1 == 2)
                in = 6 + j1;
            int temp = mat[i][j] % maxi;
            if (temp)
            {
                mat[in][temp - 1] += maxi;
                if (mat[in][temp - 1] / maxi > 1)
                    return false;
            }
        }
    }

    return true;
}

int main()
{
    vector<vector<int>> mat(9, vector<int>(9, 0));
    for (int i = 0; i < 81; i++)
        cin >> mat[i / 9][i % 9];

    cout << isValid(mat) << "\n";

    return 0;
}