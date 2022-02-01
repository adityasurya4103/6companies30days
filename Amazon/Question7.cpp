#include <bits/stdc++.h>

using namespace std;

string FirstNonRepeating(string A)
{
    // Code here
    queue<int> q;
    string temp = "";
    int arr[26] = {0};
    for (int i = 0; i < A.size(); i++)
    {
        arr[A[i] - 'a']++;
        if (arr[A[i] - 'a'] == 1)
        {
            q.push(A[i]);
        }
        while (!q.empty() && arr[q.front() - 'a'] != 1)
        {
            q.pop();
        }
        if (q.empty())
        {
            A[i] = '#';
        }
        else
        {
            A[i] = q.front();
        }
    }
    return A;
}

int main(){

		string A;
		cin >> A;

		string ans =FirstNonRepeating(A);
		cout << ans << "\n";

	return 0;
}  