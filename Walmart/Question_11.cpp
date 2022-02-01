bool static cmp(vector<int> &a , vector<int> &b)
{
   return a[1] > b[1];
}

int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k)
{
    vector<vector<int>> eng;
    unsigned long long m = 10e9+7;
    for(int i=0 ; i<n ; i++) eng.push_back({speed[i] , efficiency[i]});
    sort(eng.begin() , eng.end() , cmp);
    priority_queue<int> pq;
    unsigned long long maxPer = 0;
    unsigned long long sum = 0;
    long minVal = 0;
    
    for(int i=0 ; i<n ; i++)
    {
        pq.push(-eng[i][0]);
        sum+=eng[i][0];
        minVal = eng[i][1];
        
        if(pq.size() > k)
        {
            sum+=pq.top();
            pq.pop();
        }
        maxPer = max(maxPer , sum*minVal);
    }
    return maxPer % 1000000007;
}
