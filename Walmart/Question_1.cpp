class Solution {
public:
    
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        vector<unordered_map<int, double>> graph(n);
        vector<bool> seen(n, 0);
        for(int i=0;i<edges.size();i++)
        {
            graph[edges[i][0]][edges[i][1]] = succProb[i];
            graph[edges[i][1]][edges[i][0]] = succProb[i];
        }
        
        vector<double> prob(n, 0.0);
        prob[start] = 1.0;
        
        priority_queue<pair<double, int>>pq;
        pq.push({1.0, start});
        
        while(!pq.empty())
        {
            int curr = pq.top().second;
            double pb = pq.top().first;
            pq.pop();
            
            if(seen[curr] == false)
            {
                seen[curr] = true;
                for(auto& it : graph[curr])
                {
                    int next = it.first;
                    double pro = it.second;

                    if(prob[curr] * pro > prob[next])
                    {
                        prob[next] = prob[curr] * pro;
                        pq.push({prob[next], next});
                    }
                }
            }
        }
        
        return prob[end];
    }
}
