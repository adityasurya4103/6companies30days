class Solution:

    #Function to find unit area of the largest region of 1s.
	def findMaxArea(self, grid):
	    ans = 0
	    def area(grid,i,j):
	       if i<0 or j<0 or i>=len(grid) or j>=len(grid[0]):
	           return 0
	       if grid[i][j]==0:
	           return 0
	       grid[i][j]=0
	       return 1+area(grid,i-1,j)+area(grid,i,j-1)+area(grid,i+1,j)+area(grid,i,j+1)+area(grid,i-1,j-1)+area(grid,i+1,j+1)+area(grid,i+1,j-1)+area(grid,i-1,j+1)
	       
	    
	    for i in range(len(grid)):
            for j in range(len(grid[0])):
		        if grid[i][j]:
		            ans=max(ans,area(grid,i,j))
		return ans
