#include <bits/stdc++.h>

using namespace std;

vector<string> AllParenthesis(int n) ;

// N is the number of pairs of parentheses

// Return list of all combinations of balanced parantheses

class Solution

{

    public:

    void solve(vector<string>&vec, string op, int open, int close)

   {

       if(open==0 && close==0)

       {

           vec.push_back(op);

           return;

       }

       if(open!=0)

       {

           string op1=op;

           op1.push_back('(');

           solve(vec,op1,open-1,close);

       }

       if(close>open)

       {

           string op1=op;

           op1.push_back(')');

           solve(vec,op1,open,close-1);

       }

   }

   vector<string> AllParenthesis(int n) 

   {


       vector<string>vec;

       string op;

       int open=n;

       int close=n;

       solve(vec,op,open,close);

       return vec;

    }

};

int main() 

{ 

	int t;

	cin>>t;

	while(t--)

	{

		int n;

		cin>>n;

		Solution ob;

		vector<string> result = ob.AllParenthesis(n); 

		sort(result.begin(),result.end());

		for (int i = 0; i < result.size(); ++i)

			cout<<result[i]<<"\n";

	}

	return 0; 

}
