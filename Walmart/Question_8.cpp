class Solution{
public:
    int height(int n){
        int ans = (-1 + sqrt(1 + (8*n))) / 2;   // Using direct formula
        return ans;
    }
}
