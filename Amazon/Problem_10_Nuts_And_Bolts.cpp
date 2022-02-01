class Solution{
public:	

	void matchPairs(char nuts[], char bolts[], int n) {
	    char arr[]={'!','#','$','%','&','*','@','^','~'};
	    set<char>s;
	    int i;
	    for(i=0;i<n;i++)
	      s.insert(nuts[i]);
	      i=0;
	      int j=0;
	     while(i<9)
	     {
	         if(s.find(arr[i])!=s.end())
	         {
	             nuts[j]=arr[i];
	             i++;
	             j++;
	         }
	         else
	         i++;
	     }
	     s.clear();
	     for(int i=0;i<n;i++)
	     s.insert(bolts[i]);
	      i=0;
	      j=0;
	     while(i<9)
	     {
	         if(s.find(arr[i])!=s.end())
	         {
	             bolts[j]=arr[i];
	             i++;j++;
	         }
	         else
	         i++;
	     }
	}
}
