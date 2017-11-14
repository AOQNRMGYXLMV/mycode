#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int dp[2][205][205], num[205][205], n;

bool islegal(int x, int y)
{
    return (x>=1 && x<=n && y>=1 && y<=n);
}

int main(void)
{
    int i, j, k, d1, d2, x1, x2, y1, y2;
    scanf("%d", &n);
    for(i = 1; i <= n; ++i)
        for(j = 1; j <= n; ++j)
            scanf("%d", &num[i][j]);

    dp[1][1][1] = num[1][1];
    int cur = 0;
    for(k = 2; k <= 2*n-1; ++k, cur ^= 1)
    {
        memset(dp[cur], 0, sizeof(dp[cur]));
        for(i = 1; i <= k - 1; ++i)
            for(j = 1; j <= i; ++j)
            {
                for(d1 = 0; d1 <= 1; ++d1)
                    for(d2 = 0; d2 <= 1; ++d2)
                    {
                        x1 = i + d1, y1 = k + 1 - x1;
                        x2 = j + d2, y2 = k + 1 - x2;
                        if(islegal(x1, y1) && islegal(x2, y2))
                        {
                            if(x1 == x2)
                                dp[cur][x1][x2] = max(dp[cur][x1][x2], dp[cur^1][i][j] + num[x1][y1]);
                            else
                                dp[cur][x1][x2] = max(dp[cur][x1][x2], dp[cur^1][i][j] + num[x1][y1] + num[x2][y2]);
                        }
                    }
            }
    }
    printf("%d\n", dp[(2*n-1)&1][n][n] + num[1][1] + num[n][n]);

    return 0;
}