#include <bits/stdc++.h>

using namespace std;

    vector <int> max_of_subarrays(int *arr, int n, int k)
    {
        // your code here    
        deque<int>q;
       int i=0,j=0;
   
       int max;
       vector<int>v1;
       while(j<n)
       {   
           while(q.size()>0 && q.back()<arr[j])
           {
               q.pop_back();
           }
           q.push_back(arr[j]);
           if(j-i+1<k)
           {
               j++;
            }
           else if(j-i+1==k)
           {
               max=q.front();
                
               v1.push_back(max);
               if(arr[i]==q.front())
               q.pop_front();
           
               i++;j++;
           }
       }
       return v1;
    }

 int main() {
	    
	    int n, k;
	    cin >> n >> k;
	    
	    int arr[n];
	    for(int i = 0;i<n;i++) 
	        cin >> arr[i];
	 
	    vector <int> res = max_of_subarrays(arr, n, k);
	    for (int i = 0; i < res.size (); i++) 
	        cout << res[i] << " ";
	    cout << endl;


        return 0;
	    
	}   