class Solution {
public:

#define fr(i , x, y)  for(int i=x; i<y ;i++)

vector<int> ans;

int ch[20009]={0};
int ls[20009]={0};

int fun(vector<int> &a){
    int n = a.size();
    
    if(n==2){
        
        if(a[0]!=0 && a[1]!=0){
            return 0;
        }
        
        if(a[0]==0){
            ans.push_back(a[1]);
            return 1;
        }
        else{
            ans.push_back(a[0]);
            return 1;
        }
    }
    
    int x=a[n-1]-a[n-2];
    
    
    
    fr(i , 0 , n){
        ls[a[i]+10000]++;
    }
    
    
    vector<int > f1, f2;
    
    int u=0;
    
    fr(i , 0 , n){
        
        if(ch[a[i]+10000]!=0){
            ch[a[i]+10000]--;
            continue;
        }
        
        int y=a[i];
        
        if(ls[y+x+10000]!=0){
            f1.push_back(y);
            f2.push_back(y+x);
            ls[y+10000]--;
            ls[y+x+10000]--;
            ch[y+x+10000]++;
        }
        else{
            
            u=1;
            break;
        }
    }
    
    fr(i , 0 , n){
        ch[a[i]+10000]=0;
        ls[a[i]+10000]=0;
    }
    
    if(u==1){
        return 0;
    }
    
    bool x1=fun(f1);
    
    
    if(x1==1){
        ans.push_back(x);
        
        return 1;
    }
    
    bool x2=fun(f2);
    
    if(x2==1){
        ans.push_back(-1*x);
        return 1;
    }
    
    return 0;
    
}
vector<int> recoverArray(int n, vector<int>& sums) {
    
    sort(sums.begin(), sums.end());
    ans.clear();
    fun(sums);
    return ans;
}
