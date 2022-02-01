#include <bits/stdc++.h>

using namespace std;

vector<vector<string>> displayContacts(int n, string contact[], string s)
{

    int i;
    string t = "";
    vector<vector<string>> ans;
    for (i = 0; i < s.size(); i++)
    {
        t += s[i];
        vector<string> v;
        set<string> st;
        for (int j = 0; j < n; j++)
        {
            int l = contact[j].find(t);
            if (l == 0)
            {
                st.insert(contact[j]);
            }
        }
        if (!st.empty())
        {
            for (auto it : st)
            {
                v.push_back(it);
            }
            ans.push_back(v);
        }
        else
        {
            v.push_back("0");
            ans.push_back(v);
        }
    }
    return ans;
}

int main()
{
    int N;
    cin >> N;

    string contact[N];
    for (int i = 0; i < N; i++)
    {
        cin >> contact[i];
    }
    string s;
    cin>>s;

    vector<vector<string>>res;
    res = displayContacts(N, contact , s);

   for(int i=0; i<s.size() ; i++){
       for(auto u: res[i]){
            cout<<u<<" ";
       }
       cout<<endl;
   }

    return 0;
}