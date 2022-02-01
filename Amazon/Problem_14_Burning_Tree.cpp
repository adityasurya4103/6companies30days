class Solution{
    int ans=0;
  pair<int,bool> dfs(Node* root, int t){
      if(root==NULL){
          return {0, false};
      }
      if(root->data==t){
          ans=max(dfs(root->left, t).first, dfs(root->right, t).first);
          return {1, true};
      }
      pair<int,bool> left = dfs(root->left, t), right = dfs(root->right, t);
      if(left.second){
          ans=max(ans, right.first+left.first);
          return {left.first+1, true};
      } else if(right.second){
          ans=max(ans, right.first+left.first);
          return {right.first+1, true};
      } else {
          return {max(left.first, right.first)+1, false};
      }
  }
  public:
    int minTime(Node* root, int target) 
    {
        // Your code goes here
        dfs(root, target);
        return ans;
    }
}
