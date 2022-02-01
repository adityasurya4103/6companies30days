#include <bits/stdc++.h>

using namespace std;

	vector<int> kLargest(int arr[], int n, int k) {
	    // code here
	    vector<int>res;
	    priority_queue<int>p;
	    
	    for(int i=0 ; i<n ; i++)
	        p.push(arr[i]);
	    while(k){
	        res.push_back(p.top());
	        p.pop();
	        k--;
	    }
        
	    
	    return res;
	    
	}

int main(){
    int n;
    cin>>n;

    int arr[n];
    for(int i=0 ; i<n ; i++)
    cin>>arr[i];

    int k=10;

    vector<int> result = kLargest(arr , n , k);

    for(int i=0 ; i<result.size() ; i++)
    cout<< result[i]<<" ";

    return 0;
}