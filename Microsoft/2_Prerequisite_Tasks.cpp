#include <bits/stdc++.h>

using namespace std;

bool isPossible(int N, vector<pair<int, int>> &p)
{
    vector<int> adj[N];
    for (auto i : p)
    {
        adj[i.first].push_back(i.second);
    }

    vector<int> indegree(N, 0);
    for (int i = 0; i < N; ++i)
    {
        for (auto it : adj[i])
        {
            indegree[it]++;
        }
    }

    queue<int> q;
    for (int i = 0; i < N; ++i)
    {
        if (indegree[i] == 0)
        {
            q.push(i);
        }
    }

    int count = 0;
    while (!q.empty())
    {
        int node = q.front();
        count += 1;
        q.pop();

        for (auto i : adj[node])
        {
            indegree[i]--;
            if (indegree[i] == 0)
            {
                q.push(i);
            }
        }
    }

    if (count == N)
        return true;
    return false;
}

int main(){
        int n,p;
        cin>>n>>p;

        vector<pair<int,int>>v;
        for(int i=0 ; i<p ;i++){
         int x,y;
         cin>>x>>y;
         v.push_back(make_pair(x,y));
        }

        if(isPossible(n,v))
        cout<<"Yes"<<endl;
        else
        cout<<"No"<<endl;

        return 0; 
    }
