#include <bits/stdc++.h>

using namespace std;

class Solution{

    public:

    vector<int> leaders(int a[], int n){

        vector<int> v;

       int leader=a[n-1];

       v.push_back(leader);

       for(int i=n-2;i>=0;i--){

           if(a[i]>=leader){

               leader=a[i];

               v.push_back(leader); 

           }

       }

      

       sort(v.begin(),v.end(), greater<int>());

       return v;

        

    }

};


int main()

{

   long long t;

   cin >> t;//testcases

   while (t--)

   {

       long long n;

       cin >> n;//total size of array

        

        int a[n];

        //inserting elements in the array

        for(long long i =0;i<n;i++){

            cin >> a[i];

        }

        Solution obj;

        //calling leaders() function

        vector<int> v = obj.leaders(a, n);

        //printing elements of the vector

        for(auto it = v.begin();it!=v.end();it++){

            cout << *it << " ";

        }

        

        cout << endl;

   }

}
