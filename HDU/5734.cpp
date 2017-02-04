#include <cstdio>

const int maxn = 100000 + 10;
typedef long long LL;

LL gcd(LL a, LL b) { return !b ? a : gcd(b, a%b); }

int main()
{
    int T; scanf("%d", &T);
    while(T--) {
        int n; scanf("%d", &n);
        LL sigma = 0, sqr = 0;
        for(int i = 0; i < n; i++) {
            LL x; scanf("%lld", &x);
            if(x < 0) x = -x;
            sqr += x * x;
            sigma += x;
        }

        LL g = gcd(sigma * sigma, n);
        LL A = -sigma * sigma / g, B = n / g;
        A += sqr * B;
        if(!A) { printf("0/1\n"); continue; }
        printf("%lld/%lld\n", A, B);
    }

    return 0;
}
