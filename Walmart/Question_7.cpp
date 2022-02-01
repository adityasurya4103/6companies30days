class Solution{
 public:
   vector<int> find3Numbers(vector<int> arr, int N) {
       vector<int> vec;
       if(N<3)
       {
           return vec;
       }
       int prev=arr[0], curr=-1, next = -1;
       for(int i=0; i<N; i++){
           if(curr!=-1 && next!=-1)
           {
               break;
           }
           if(arr[i]<prev && curr==-1)
           {
               prev = arr[i];
           }
           else if(arr[i]>prev && curr==-1)
           {
               curr = arr[i];
           }
           else if(arr[i]>prev && arr[i]<curr)
           {
               curr = arr[i];
           }
           else if(arr[i]>curr && curr!=-1 && next==-1){
               next = arr[i];
           }
           
       }
       if(curr!=-1 && next!=-1)
       {
           vec.push_back(prev);
           vec.push_back(curr);
           vec.push_back(next);
       }
       return vec;
   }
}
