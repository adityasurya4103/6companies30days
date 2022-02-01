 #include <bits/stdc++.h>

using namespace std;

int countSubArrayProductLessThanK(vector<int>& a, int n, long long k) {
         int i=0,j=0,ans=0;
        long long prod = 1;
        while(j < n){
            prod *= a[j];
            if(prod >= k){
                while(i <= j and prod >= k){
                    prod /= a[i];
                    i++;
                }
            }
            ans += j-i+1;
            j++;
        }
        return ans;
    }

int main(){
    int n,i;
    cin>>n;
    long long k;
    cin>>k;

    vector<int>arr(n);
    for(i=0 ; i<n ; i++)
        cin>>arr[i];
    
    int result = countSubArrayProductLessThanK(arr , n , k);

    cout<<result<<endl;

    return 0;
}