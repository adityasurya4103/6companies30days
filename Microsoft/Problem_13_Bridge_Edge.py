class Solution:
    def DFS(self, adj, v, visited): 
          
         
        visited[v] = True
      
        i = 0
        
        while i != len(adj[v]): 
            
            
            if (not visited[adj[v][i]]):  
                self.DFS(adj, adj[v][i], visited) 
            i += 1
      

    def isConnected(self, V, adj, one, two): 
        
        visited = [False] * V 
      
        
        self.DFS(adj, one, visited)  
        
        if (visited[two] == False):  
                return False
        return True

    def isBridge(self, V, adj, u, v):
        
        
        if self.isConnected(V,adj,u,v) == False:
            return 0
        
       
        indU = adj[v].index(u) 
        indV = adj[u].index(v) 
        del adj[u][indV]  
        del adj[v][indU]  
       
        
        res = self.isConnected(V, adj, u, v)  
      
        #adding the edges back  
        adj[u].append(v)   
        adj[v].append(u)    
     
        if (res == False):
            return 1 
        else:
            return 0
