#include <bits/stdc++.h>

using namespace std;

int main() {

    int n;

    cin >> n;

    vector<vector<int>> V(n);

    for (int i = 0; i < n; ++i) {

        string version;

        cin >> version;

        V[i].push_back(0);

        for(char c: version) {

            if(c == '.') 

                V[i].push_back(0);

            else

                V[i].back() =  V[i].back()*10 + c - '0';

        }

    }

    sort(V.begin(), V.end());

    bool dot = false;

    for(auto n: V.back()) {

        if(dot) cout << ".";

        cout << n;

        dot = true;

    }

    return 0;

}
