#include <bits/stdc++.h>

using namespace std;

int findInMountainArray(int target, vector<int>&m) {
        int l=1;int r=m.size()-1;
int t=-1;

    while(l<=r)
    {
      int mid=(l+r)/2;
      int idx=m[mid];
      int idxl=m[mid-1];
      int idxr=m[mid+1];
      if(idx>idxl&&idx>idxr)
      {
        t=mid;
        break;
      }
      else if(idxr>idx&&idx>idxl)
        l=mid+1;
      else if(idxr<idx&&idx<idxl)
        r=mid-1;

    }

    l=0;r=t;

    while(l<=r)
    {
      int mid=(l+r)/2;
      int x=m[mid];
      if(x==target)
      {
        return mid;
      }
      else if(x<target)
        l=mid+1;
      else
        r=mid-1;
    }

    l=t;r=m.size()-1;

    while(l<=r)
    {
      int mid=(l+r)/2;
      int x=m[mid];
      if(x==target)
      {
        return mid;
      }
      else if(x<target)
        r=mid-1;
      else
        l=mid+1;
    }
    return -1;

    }

    int main()
{
    int n;
    cin >> n;

    vector<int> a(n);

    for (int i = 0; i < n; i++)
        cin >> a[i];

    int target;
    cin >> target;

    int res = findInMountainArray(target ,a);

    cout << res << endl;

    return 0;
}