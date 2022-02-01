 
 ​#include <iostream>  
 ​using namespace  std;  
 ​  
 ​long long int noofsq(int n){  
 ​    return (n*(n+1)/2)*(2*n+1)/3;  
 ​}  
 ​int main(){  
 ​    int n;  
 ​    cin>>n;  
 ​    cout<<noofsq(n);  
 ​    return 0;  
 ​} 
