#include <bits/stdc++.h>
using namespace std;

vector<string> generate(int N)
{
	vector<string>res ;
	queue<string>q;
	q.push("1");
	for(int count=0 ; count<N ; count++){
	    string curr = q.front();
	    res.push_back(curr);
	    q.pop();
	    q.push(curr + '0');
	    q.push(curr + '1');
	}
	return res ;
	
	
}

int main()
{
        int n;
        cin>>n;

        vector<string>res = generate(n);

        for (int i = 0; i < res.size() ; ++i)
        {
            cout<<res[i]<<" ";
        }
    
    return 0;
}
