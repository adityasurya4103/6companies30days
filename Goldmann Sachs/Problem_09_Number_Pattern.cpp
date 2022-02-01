 
 ​#include <iostream>  
 ​using namespace std;  
 ​  
 ​class Solution{  
 ​    public:  
 ​    string Pattern(string s){  
 ​        string x="";  
 ​        int i=0,j=0;  
 ​        int count=1;  
 ​        while(i<=s.size()){  
 ​            if(s[i]=='I'||i==s.size()){  
 ​                while(count>=1){  
 ​                    if(count<=j)break;  
 ​                    char ch=count+'0';  
 ​                    x.push_back(ch);  
 ​                    count--;  
 ​                }  
 ​                j=i+1;  
 ​                count=i+1;  
 ​            }  
 ​            count++;  
 ​            i++;  
 ​        }  
 ​        return x;  
 ​    }  
 ​};  
 ​int main(){  
 ​    string s;  
 ​    cin>>s;  
 ​    Solution s1;  
 ​    cout<<s1.Pattern(s);  
 ​    return 0;  
 ​} 
