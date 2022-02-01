 
 ​#include <iostream>  
 ​using namespace std;  
 ​class solution {  
 ​    public:  
 ​  
 ​int CountWays(string str){  
 ​                    // Code here  
 ​                    int n = str.size();  
 ​                    const int mod = 1e9 + 7;  
 ​                          
 ​                    if(str[0] == '0')  
 ​                        return 0;  
 ​                          
 ​                    for(int i = 0; i < n-1; i++) {  
 ​                          
 ​                        if(str[i] == '0' && str[i+1] == '0')  
 ​                            return 0;  
 ​                    }  
 ​                      
 ​                    int table[n+1] = {0};  
 ​                    table[0] = 1;  
 ​                      
 ​                    for(int i = 0; i < n; i++) {  
 ​                          
 ​                        if(str[i] == '0')  
 ​                            continue;  
 ​                          
 ​                        table[i+1] = (table[i+1] + table[i])%mod;  
 ​                          
 ​                        if(i != n-1)  
 ​                        if(str[i] == '1'   
 ​                            || (str[i] == '2' && str[i+1] < '7'))  
 ​                              
 ​                            table[i+2] = (table[i+2] + table[i])%mod;  
 ​                    }  
 ​                      
 ​                    return table[n];  
 ​                }  
 ​  
 ​};  
 ​  
 ​int main(){  
 ​    string str;  
 ​    cin>>str;  
 ​    solution s1;  
 ​    int ans=s1.CountWays(str);  
 ​    cout<<ans;  
 ​    return 0;  
 ​}
