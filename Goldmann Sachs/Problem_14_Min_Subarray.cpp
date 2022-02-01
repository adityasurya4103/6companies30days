 
 ​class Solution {  
 ​public:  
 ​    int minSubArrayLen(int target, vector<int>& nums)   
 ​    {  
 ​        int i=0,j=0;  
 ​        int size=nums.size();  
 ​          
 ​        int mi=INT_MAX;  
 ​        int sum=0;  
 ​        while(j<size)  
 ​        {  
 ​            sum=sum+nums[j];  
 ​              
 ​            if(sum<target)  
 ​            {  
 ​                j++;  
 ​            }  
 ​            else if(sum>=target)  
 ​            {  
 ​               while(sum>=target)  
 ​               {  
 ​                   mi=min(mi,j-i+1);  
 ​                   sum=sum-nums[i];  
 ​                   i++;  
 ​               }  
 ​                j++;  
 ​            }  
 ​        }  
 ​          
 ​        if(mi==INT_MAX)  
 ​        {  
 ​            return 0;  
 ​        }  
 ​        else  
 ​        {  
 ​            return mi;  
 ​        }  
 ​    }  
 ​};
