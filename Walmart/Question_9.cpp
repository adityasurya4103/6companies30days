int getMinCost(int n){
    int dp[n][n];
    memset(dp, 0, sizeof(dp));
    for(int g = 0; g < n ; g++){
        for(int i = 0, j = g; j < n; j++,i++){
            if(g == 0){
                dp[i][j] = 0;
            }
         else if(g == 1){
                dp[i][j] = min(i + 1, j + 1);
            }
         else{
                int maxMinCost = INT_MAX;
                for(int guess = i; guess <= j; guess++){
                    int leftCost = (i == guess) ? 0 : dp[i][guess-1];
                    int rightCost = (j == guess) ? 0 : dp[guess + 1][j];
                    int currCost = guess + 1;
                    int totalCost = currCost + max(leftCost, rightCost); // take max
                    maxMinCost = min(maxMinCost, totalCost);// take min
              }
                dp[i][j] = maxMinCost;
            }
        }
    }
    return dp[0][n-1];
}
