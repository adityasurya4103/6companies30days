#include<bits/stdc++.h>
using namespace std;

class Solution
{
    int nCr(int n, int r){
        long res=1.0;
        for(int i=1;i<=r;++i){
            res = res*(n-r+i) / i;
        }
        return (int)res;
    }
    public:
    int NumberOfPath(int a, int b){
        
        if(a==1 || b==1)return 1; 
        int steps_to_right = b-1;
        int steps_down = a-1; 
        int total_steps = steps_to_right + steps_down; 
        if(steps_down < steps_to_right)
            return nCr(total_steps, steps_down);
        return nCr(total_steps, steps_to_right);
    }
};

int main()
{
    //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        int a,b;
        cin>>a>>b;
        Solution ob;
        cout << ob.NumberOfPath(a,b) << endl;
    }
}
