class Solution{

public:
 
   int prime=1000000007;
   long long power(int n,int R)
   {
     long long res=1,N=n;
      if(N==0)
      return 0;
      if(R==0)
         return 1;
      while(R>0){
          if(R&1)
          res=(res*N)%prime;
          R=R>>1;
          N=(N*N)%prime;
      }
      return res%prime;
   }
