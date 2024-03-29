#include <iostream>
#include <cstdio>
#include <algorithm>
#include<cstring>
using namespace std;
 
const int MAXN = 2016;
 
int n;
int dp[MAXN][MAXN];
int a[MAXN];
 
int main()
{
    while (~scanf("%d", &n)) {
        for (int i = 1; i <= n; ++i) {
            scanf("%d", a+i);
        }
        sort(a+1, a+1+n);
        memset(dp, 0, sizeof dp);
        int res = 0;
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j < i; ++j) {
                dp[i][a[i]-a[j]] = max(dp[i][a[i]-a[j]], dp[j][a[i]-a[j]]+1);
                res = max(res, dp[i][a[i]-a[j]]);
            }
        }
        printf("%d\n", res+1);
    }
}