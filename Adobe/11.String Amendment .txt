// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution{
    public:
    string amendSentence (string s)
    {
        // your code here
         if(s.size() == 0) return s;
        vector<string> v;
        string temp = "";
        for(int i=0; i<s.size(); i++){
            char c = s[i];
            if(c >= 'A' and c <= 'Z'){
                v.push_back(temp);
                temp = "";
                temp += c;
            } else {
                temp += c;
            }
        }
        v.push_back(temp);
        
        string res = "";
        
        for(auto str:v){
            string t = "";
            for(int i=0; i<str.size(); i++){
                t += tolower(str[i]);
            }
            res += t + " ";
        }
        
        if(res[0] == ' ') res.erase(0, 1);
        if(res[res.size()-1] == ' ') res.erase(res.size()-1, res.size());
        return res;
    }
};

// { Driver Code Starts.
int main()
{
	int t; cin >> t;
	while (t--)
	{
		string s; cin >> s;
		Solution ob;
		cout << ob.amendSentence (s) << endl;
	}
}  // } Driver Code Ends