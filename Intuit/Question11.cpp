/*
// Definition for a QuadTree node.
class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;
    
    Node() {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};
*/

class Solution {
public:
    vector<vector<int>> area,Grid;
    
    Node* buildTree(int rs,int re,int cs,int ce){
        if(rs==re || cs==ce){
            Node *n = new Node(Grid[rs-1][cs-1],true);
            return n;
        }
        int a = area[re][ce]-area[re][cs-1]-area[rs-1][ce]+area[rs-1][cs-1];
        if(a==0 || a==(re-rs+1)*(ce-cs+1)){
            Node *n = new Node(a>0,true);
            return n;
        }
        int midrow = rs+(re-rs)/2;
        int midcol = cs + (ce-cs)/2;
        Node *n = new Node(0,false);
        n->topLeft = buildTree(rs,midrow,cs,midcol);
        n->topRight = buildTree(rs,midrow,midcol+1,ce);
        n->bottomLeft = buildTree(midrow+1,re,cs,midcol);
        n->bottomRight = buildTree(midrow+1,re,midcol+1,ce);
        return n;
    }
    
    Node* construct(vector<vector<int>>& grid) {
        int n = grid.size();
        Grid=grid;
        area.clear();
        for(int i=0;i<n+1;i++){
            vector<int> tmp(n+1,0);
            area.push_back(tmp);
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(i==1 && j==1)
                    area[i][j]=grid[i-1][j-1];
                else if(i==1)
                    area[i][j]=grid[i-1][j-1]+area[i][j-1];
                else if(j==1)
                    area[i][j]=grid[i-1][j-1]+area[i-1][j];
                else
                    area[i][j]=grid[i-1][j-1]+area[i][j-1]+area[i-1][j]-area[i-1][j-1];
            }
        }
        return buildTree(1,n,1,n);
        
    }
};