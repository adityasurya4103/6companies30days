 
 ​  #include<iostream>  
 ​    
 ​  using namespace std;  
 ​  class Solution {  
 ​public:  
 ​   int gcd(int a, int b)  
 ​    {  
 ​        if(a == 0) return b;  
 ​        if(b == 0) return a;  
 ​        if(a == b) return a;  
 ​          
 ​        if(a > b) return gcd(a - b, b);  
 ​        return gcd(a, b - a);  
 ​    }  
 ​     string gcdStrings(string str1, string str2) {  
 ​        if(str1+str2==str2+str1){  
 ​            return str1.substr(0,gcd(str1.length(),str2.length()));  
 ​        }  
 ​        else{  
 ​            return "";  
 ​        }  
 ​    }  
 ​  };  
 ​  int main(){  
 ​      string str1,str2;  
 ​      cin>>str1>>str2;  
 ​      Solution s1;  
 ​      cout<<s1.gcdStrings(str1,str2);  
 ​      return 0;  
 ​  } 
