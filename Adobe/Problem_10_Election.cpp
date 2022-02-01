#include <iostream>

#include <map>

#include <algorithm>

#include <cstdlib>

#include<bits/stdc++.h>

using namespace std;

class Solution{

  public:

    vector<string> winner(string arr[],int n)

    {


        map<string, int> omap;

        vector<string> vect;

        string str = "";

        int max = 0;

        

        for(int i = 0; i < n; i++) omap[arr[i]]++;

        

        for(auto i : omap){

            

            if(i.second > max){

                str = i.first;

                max = i.second;

            }

        }

        vect.push_back(str);

        vect.push_back(to_string(max));

        return vect;

    }

};


int main()

{

    int t;

    cin>>t;

    

    for(int i=0;i<t;i++)

    {

        int n;

        cin>>n;

        string arr[n];

        for (int i=0;i<n;i++)

        cin>>arr[i];

        Solution obj;

        vector<string> result = obj.winner(arr,n);

        cout<<result[0] << " " << result[1] << endl;

    }

    return 0;

}
