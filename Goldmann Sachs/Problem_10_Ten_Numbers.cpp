 
 ​  
 ​#include <bits/stdc++.h>  
 ​  
 ​using namespace std;  
 ​  
 ​class Solution{  
 ​public:   
 ​vector<int> kLargest(int arr[], int n, int k) {  
 ​    // code here  
 ​    vector<int> v;  
 ​    int j=1;  
 ​    sort(arr,arr+n);  
 ​    while(k--)  
 ​    {  
 ​  
 ​        v.push_back(arr[n-j]);  
 ​        j++;  
 ​    }  
 ​    return v;  
 ​      
 ​}  
 ​  
 ​};  
 ​  
 ​  
 ​int main() {  
 ​   int t;  
 ​   cin >> t;  
 ​   while (t--) {  
 ​       int n, k;  
 ​       cin >> n >> k;  
 ​       int arr[n];  
 ​       for (int i = 0; i < n; i++) {  
 ​           cin >> arr[i];  
 ​       }  
 ​       Solution ob;  
 ​       auto ans = ob.kLargest(arr, n, k);  
 ​       for (auto x : ans) {  
 ​           cout << x << " ";  
 ​       }  
 ​       cout << "\n";  
 ​   }  
 ​   return 0;  
 ​}  
 ​ 
