//code runs in c++17 without warning

#include <bits/stdc++.h>
using namespace std;

int orangesRotting(vector<vector<int>> &grid)
{
    int row = grid.size();
    int col = grid[0].size();
    queue<pair<int, int>> bfsQ;
    bool possibility = false;
    int count_unrot = 0;
    for (int i = 0; i < row; ++i)
    {
        for (int j = 0; j < col; ++j)
        {
            if (grid[i][j] == 2)
            {
                bfsQ.push(make_pair(i, j));
            }
            if (grid[i][j] == 1)
            {
                count_unrot++;
            }
        }
    }
    if (count_unrot == 0)
    {
        return 0;
    }
    bfsQ.push(make_pair(-1, -1));

    int dir[4][2] = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
    int elapsedMin = 0;

    while (!bfsQ.empty())
    {
        auto [m, n] = bfsQ.front();
        bfsQ.pop();
        if (m == -1 && n == -1)
        {
            if (!bfsQ.empty())
            {
                // use a delimiter in the queue to separate cells on different levels
                bfsQ.push(make_pair(-1, -1));
                elapsedMin++;
            }
            continue;
        }

        for (int i = 0; i < 4; ++i)
        { // move in all possible directions from rotten oranges.
            int new_r = m + dir[i][0];
            int new_c = n + dir[i][1];
            if (new_r >= 0 && new_r < row && new_c >= 0 && new_c < col)
            {
                if (grid[new_r][new_c] == 1)
                {
                    count_unrot--;
                    grid[new_r][new_c] = 2;
                    bfsQ.push(make_pair(new_r, new_c));
                }
            }
        }
    }

    if (count_unrot)
        return -1;

    return elapsedMin;
}

int main()
{
    int M, N;
    cin >> M >> N;

    vector<vector<int>> grid;
    int val;
    for (int i = 0; i < M; i++)
    {
        vector<int> temp;
        for (int j = 0; j < N; j++)
        {
            cin >> val;
            temp.push_back(val);
        }
        grid.push_back(temp);
        temp.clear();
    }

    int result = orangesRotting(grid);

    cout << result << endl;

    return 0;
}
