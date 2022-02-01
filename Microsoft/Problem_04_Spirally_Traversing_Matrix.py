class Solution:
    
    #Function to return a list of integers denoting spiral traversal of matrix.
    def spirallyTraverse(self,matrix, m, n):
        ans =[]
        x,y,dx,dy=0,0,1,0
        for _ in range(n*m):
            if not 0<= x+dx < n or not 0<= y+dy <m or matrix[y+dy][x+dx]=="*":
                dx,dy = -dy,dx
            ans.append(matrix[y][x])
            matrix[y][x] = "*"
            x, y = x + dx, y + dy
            
                    
        return 
