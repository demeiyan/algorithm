#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        if(n <= 1)return 0;
        int dp[n+1][2];
        dp[0][0] = 0;
        dp[0][1] = INT_MIN;
        for(int i = 1;i <= n;i++){
            dp[i][0] = max(dp[i-1][0], dp[i-1][1] + prices[i-1] );
            dp[i][1] = max(dp[i-1][1], dp[i-1][0] - prices[i-1]- fee);
        }      
        return dp[n][0];
    }
};