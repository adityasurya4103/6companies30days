class Solution{
   int data=0;
   public int traverse(Node root , int left,int right){
       
       if(root==null)
          return 0;
          
       if(root.right==null&&root.left==null){
           data=root.data;
           root.data=0;
           return data;
       }
       left = traverse(root.left ,left,right);
       right= traverse(root.right ,left,right);
           data= root.data;
           if(root.left!=null&&root.right!=null)
           {
               root.data=root.left.data+left+root.right.data+right;
           }
           else if(root.left==null){
               root.data=root.right.data+right;
           
           }
            else if(root.right==null){
               root.data=root.left.data+left;
           }
         return data;
   }
   public void toSumTree(Node root){
        traverse(root,0,0);
   }
}
