 
 ​#include <iostream>  
 ​#include <unordered_map>  
 ​using namespace std;  
 ​int main(){  
 ​    int n;  
 ​    cin>>n;  
 ​    int arr[n];  
 ​    for(int i=0;i<n;i++)  
 ​    cin>>arr[i];   
 ​    unordered_map<int,bool>mp;  
 ​    for(int i:arr){  
 ​        if(mp.find(i)==mp.end())  
 ​        mp[i]=true;  
 ​        else   
 ​        cout<<i<<"is repeating"<<endl;  
 ​    }  
 ​    for(int i=1;i<n;i++){  
 ​        if(mp.find(i)==mp.end())  
 ​        cout<<i<<"is missing"<<endl;  
 ​    }  
 ​    return 0;  
 ​}
