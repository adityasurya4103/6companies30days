#include <bits/stdc++.h>
using namespace std;

class Solution{
    public:
        void topo(vector<int> adj[], int u, bool visited[], stack<int> &s)
    {
        //marking the current vertex as visited.
        visited[u] = true;

        //traversing over the adjacent vertices.
        for (auto v : adj[u])
        {
            //if any vertex is not visited, we call the function recursively.
            if (!visited[v])
                topo(adj, v, visited, s);
        }
        //pushing the current vertex into the stack.
        s.push(u);
    }

    
    string toposort(int k,vector<int>adj[]){
        bool visited[k + 1];
        memset(visited, 0, sizeof(visited));
        string str="";
        stack<int> s;

        //traversing over all the vertices.
        for (int i = 0; i <k; i++)
        {
            //if the current vertex is not visited, we call the topo function.
            if (!visited[i])
                topo(adj, i, visited, s);
        }
        int i = -1;
        while (!s.empty())
        {
            //pushing elements of stack in list and popping them from stack.
            str+=(s.top() +'a');
            s.pop();
        }
        //returning the list.
        return str;
    }
    string findOrder(string dict[], int N, int K)
   {
        string s="";
        vector<int> adj[K];
        
        for(int i=0; i< N-1; i++){
            string a=dict[i], b=dict[i+1];
            for(int j=0;j< min(a.length(), b.length());j++){
                if(a[j]!=b[j]){
                    adj[a[j]-'a'].push_back(b[j]-'a');
                    break;
                }
            }
        }
        
        return toposort(K,adj);
   }
};

string order;
bool f(string a, string b) {
    int p1 = 0;
    int p2 = 0;
    for (int i = 0; i < min(a.size(), b.size()) and p1 == p2; i++) {
        p1 = order.find(a[i]);
        p2 = order.find(b[i]);
        //	cout<<p1<<" "<<p2<<endl;
    }

    if (p1 == p2 and a.size() != b.size()) return a.size() < b.size();

    return p1 < p2;
}


int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> N >> K;
        string dict[N];
        for (int i = 0; i < N; i++) cin >> dict[i];
        
        Solution obj;
        string ans = obj.findOrder(dict, N, K);
        order = "";
        for (int i = 0; i < ans.size(); i++) order += ans[i];

        string temp[N];
        std::copy(dict, dict + N, temp);
        sort(temp, temp + N, f);

        bool f = true;
        for (int i = 0; i < N; i++)
            if (dict[i] != temp[i]) f = false;

        if(f)cout << 1;
        else cout << 0;
        cout << endl;
    }
    return 0;
}
