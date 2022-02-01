class Solution{
    public:
		string FirstNonRepeating(string A){
		    queue<int> q;
		    int a[26]={0};
		    for(int i=0;i<A.size();i++){
		        a[A[i]-'a']++;
		        if(a[A[i]-'a']==1){
		            q.push(A[i]);
		        }
		        while(!q.empty() && a[q.front()-'a']!=1){
		            q.pop();
		        }
		        if(q.empty()){
		            A[i]='#';
		        }else{
		            A[i]=q.front();
		        }
		    }
		    return A;
		}
};
