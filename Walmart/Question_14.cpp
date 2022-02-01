class Solution
{
   static String ans="";
   public static String findMaximumNum(String str, int k)
   {
       ans=str;
       maxima(str.toCharArray(),k,0);
       return ans;
   }

   public static void maxima(char[] str,int k,int idx)
   {
       if(k==0||idx==str.length)
       {
           String sp=new String(str);
           if(ans.compareTo(sp)<0)
           {
               ans=sp;
           }
           return;
       }
       char max=str[idx];
       for(int i=idx+1;i< str.length;i++)
       {
           if(str[i]>max)
           {
               max=str[i];
           }
       }
       if(max!=str[idx])
       {
           k--;
       }

       for(int i=idx;i<=str.length-1;i++)
       {
           if(str[i]==max)
           {
               swap(str,idx,i);
               maxima(str,k,idx+1);
               swap(str,i,idx);
           }
       }
   }
      public static void swap(char []s,int i,int j)
   {
       char temp=s[i];
       s[i]=s[j];
       s[j]=temp;
       return;
   }
}
