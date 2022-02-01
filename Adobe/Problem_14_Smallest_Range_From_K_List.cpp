#include<bits/stdc++.h>

using namespace std;

#define N 1000

class Solution{

    public:

    pair<int,int> findSmallestRange(int arr[][N], int n, int k)

    {

           priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;

       int maxi=INT_MIN,minrange=INT_MAX,start;

       for(int i=0;i<k;i++) 

       {

          pq.push(make_pair(arr[i][0],i));

          maxi=max(maxi,arr[i][0]);

       }

       int a[k]={0};

       while(1)

       {

           pair<int,int> p=pq.top();

           pq.pop();

           int mini=p.first;

           int range=maxi-mini;

           if(range<minrange) 

           {

               start=mini;

               minrange=range;

           }

           a[p.second]++;

           if(a[p.second]==n)

           break;

           pq.push(make_pair(arr[p.second][a[p.second]],p.second));

           maxi=max(maxi,arr[p.second][a[p.second]]);

       }

       return make_pair(start,minrange+start);

    }

};

int main()

{

    int t;

    cin>>t;

    while(t--)

    {

        int n, k;

        cin>>n>>k;

        int arr[N][N];

        pair<int,int> rangee;

        for(int i=0; i<k; i++)

            for(int j=0; j<n; j++)

                cin>>arr[i][j];

        Solution obj;

	    rangee = obj.findSmallestRange(arr, n, k);

	    cout<<rangee.first<<" "<<rangee.second<<"\n";

    }   

	return 0;

}
