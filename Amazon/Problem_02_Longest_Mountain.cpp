class Solution {
public:
    int longestMountain(vector<int>& arr) {
        int ans =0;
        int n = arr.size();
        int i=0;
        while(i<n){
            int j=i;
            int l=1, r=1;
            while(j+1<n && arr[j]<arr[j+1]){
                l++;
                j++;
            }
            while(j+1<n && arr[j]>arr[j+1]){
                r++;
                j++;
            }
            if(l>1 && r>1) 
                ans = max(ans,l+r-1);
            if(l==1 && r==1) i++;
            else i=j;
        }
        return ans;
    }
}
