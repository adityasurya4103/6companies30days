 
 ​#include <bits/stdc++.h>  
 ​using namespace std;  
 ​class solution {  
 ​    public:  
 ​     string decodedString(string s){  
 ​  int l = 0, r = s.size() - 1;  
 ​        return decodeUtil(s, l, r);  
 ​    }  
 ​      
 ​    string decodeUtil(string &s, int l, int r) {  
 ​        int times = 0;  
 ​        string ans = "";  
 ​        stack<char> st;  
 ​        for(int i = l; i <= r; i++) {  
 ​            if(isdigit(s[i])) times = times * 10 +  (s[i] - '0');  
 ​            else if(s[i] == '[') {  
 ​                if(times == 0) times = 1;  
 ​                int j = i + 1;  
 ​                while(s[j] != ']' || !st.empty()) {  
 ​                    if(s[j] == ']') st.pop();  
 ​                    else if(s[j] == '[') st.push('[');  
 ​                    j++;  
 ​                }  
 ​                string rec = decodeUtil(s, i + 1, j - 1);  
 ​                i = j;  
 ​                while(times != 0) {  
 ​                    ans = ans + rec;  
 ​                    times--;  
 ​                }  
 ​            } else ans = ans + s[i];  
 ​        }  
 ​        return ans;  
 ​    }  
 ​};  
 ​int main(){  
 ​    string s;  
 ​    cin>>s;  
 ​    solution s1;  
 ​    cout<<s1.decodedString(s)<<"\n";  
 ​    return 0;  
 ​}
