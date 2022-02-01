 #include <bits/stdc++.h>

using namespace std;

int findPosition(int N , int M , int K) {
        // code here
        if((M+K-1) <= N)
            return M+K-1;
        if((M+K-1)%N ==0)    
        return N;
        else
        return (M+K-1)%N; 
    }

int main(){
int N,M,K;
cin>> N >> M >>K;

int res = findPosition(N ,M ,K);

cout<<res<<endl;

}