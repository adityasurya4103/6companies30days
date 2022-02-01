 
 ​#include<iostream>  
 ​#include<bits/stdc++.h>  
 ​using namespace std;  
 ​  
 ​int lastPosition(int n,int m,int k){  
 ​    if(m<=n-k+1)  
 ​    return m+k-1;  
 ​      
 ​    m=m-(n-k+1);  
 ​    if(m%n==0)return n;  
 ​    else return m%n;  
 ​}  
 ​  
 ​int main(){  
 ​    int n,m,k;  
 ​    cout<<"Enter size of circle:";  
 ​    cin>>n;  
 ​    cout<<"\nEnter Number of Items:";  
 ​    cin>>m;  
 ​    cout<<"\nEnter Initial Position:";  
 ​    cin>>k;  
 ​    cout<<lastPosition(n,m,k);  
 ​    return 0;  
 ​} 
