#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

typedef long long LL;
const int maxn = 700000;

int n, t, cnt;
LL base;
LL a[maxn], dp[maxn];

void solve(LL day, LL PD)
{
    LL k = 0;
    if(day > t * 2) k = (day - t * 2) / t;
    base += k * PD;
    for (int i = 0; i < day - k * t; i++)
        a[++cnt] = PD;
}

int main()
{
    int T; scanf("%d", &T);
    for (int kase = 1; kase <= T; kase++)
    {
        LL PD, PN;
        scanf("%d%d%lld%lld", &n, &t, &PD, &PN);

        base = 0;
        cnt = 0;
        while(n--)
        {
            LL day, night;
            scanf("%lld%lld", &day, &night);
            solve(day, PD);
            solve(night, PN);
        }

        dp[1] = a[1];
        for(int i = 2; i <= t; i++) dp[i] = max(dp[i - 1], a[i]);
        for(int i = t + 1; i <= cnt; i++) dp[i] = max(dp[i - 1], dp[i - t] + a[i]);

        printf("Case %d: %lld\n", kase, base + dp[cnt]);
    }
}
