class Solution{
    public:
    string colName (long long int n)
    {
        string ans="";
        while(n>0)
        {
         char ch=char(65+(n-1)%26);
         ans=ch+ans;
         n=(n-1)/26;
        }
        return ans;
    }
}
