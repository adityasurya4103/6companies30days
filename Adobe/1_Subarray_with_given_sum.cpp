#include<bits/stdc++.h>

using namespace std;

vector<int> subarraySum(int arr[], int n, long long s)
    {
        // Your code here
        int l=0;
        long long sum=0;
        for(int i=0;i<n;i++){
        sum+=arr[i];
        while(sum>=s){
        if(sum==s){
            return vector<int>{l+1,i+1};
        }
        sum-=arr[l];
        l++;
    }
    
}
return vector<int>{-1};
    }

int main(){
    int n;
    cin>>n;

    long long s;
    cin>>s;

    int arr[n];

    for(int i=0 ; i<n ; i++)
    cin>>arr[i];

    vector<int>res = subarraySum(arr, n,s);

    for(int i=0 ; i<res.size() ; i++)
    cout<<res[i]<<" ";


    return 0;
}    