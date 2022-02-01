 ​#include<iostream>  
 ​#include <vector>  
 ​# <unordered_map>  
 ​  
 ​using namespace std;  
 ​class Solution{  
 ​    public:  
 ​bool canPair(vector<int> nums, int k) {  
 ​          unordered_map <int, int> ump;  
 ​       int n = nums.size();  
 ​       for (int i=0; i<n; i++){  
 ​           ump[nums[i]%k]++;  
 ​       }  
 ​         
 ​       for (int i=0; i<n; i++){  
 ​           int rem = nums[i]%k;  
 ​             
 ​           if (rem ==0){  
 ​               if (ump[rem]%2 !=0){  
 ​                   return false;  
 ​               }  
 ​           }  
 ​             
 ​           else if (2*rem == k){  
 ​               if (ump[rem]%2 !=0){  
 ​                   return false;  
 ​               }  
 ​           }  
 ​             
 ​           else{  
 ​               if (ump[rem] != ump[k-rem]){  
 ​                   return false;  
 ​               }  
 ​           }  
 ​       }  
 ​       return true;  
 ​    }  
 ​};  
 ​int main(){  
 ​int n,k;  
 ​cin>>n,k;  
 ​vector<int>nums(n);  
 ​for(int i=0;i<nums.size();i++)cin>>nums[i];  
 ​Solution s1;  
 ​bool ans=s1.canPair(nums,k);  
 ​if(ans)  
 ​cout<<"Ture\n";  
 ​else cout<<"false\n";  
 ​return 0;  
 ​}
