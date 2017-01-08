#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int maxn = 50000 + 10;
const int maxnode = maxn * 4;

const int prime[] = { 7, 13, 17, 19 };

int val[4][20][maxnode];
int n, m;
char op[maxn], tmp[5];
int x[maxn];

int pow_mod(int a, int b, int mod) {
    int ans = 1;
    while(b) {
        if(b & 1) ans = ans * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return ans;
}

int calc(int a, char op, int b, int mod) {
    if(op == '+') return ((a + b) % mod);
    if(op == '*') return a * b % mod;
    return pow_mod(a, b, mod);
}

void pushup(int o) {
    for(int i = 0; i < 4; i++)
        for(int j = 0; j < prime[i]; j++) {
            int t = val[i][j][o<<1];
            val[i][j][o] = val[i][t][o<<1|1];
        }
}

void build(int o, int L, int R) {
    if(L == R) {
        for(int i = 0; i < 4; i++)
            for(int j = 0; j < prime[i]; j++)
                val[i][j][o] = calc(j, op[L], x[L], prime[i]);
        return;
    }
    int M = (L + R) / 2;
    build(o<<1, L, M);
    build(o<<1|1, M+1, R);
    pushup(o);
}

void update(int o, int L, int R, int p) {
    if(L == R) {
        for(int i = 0; i < 4; i++)
            for(int j = 0; j < prime[i]; j++)
                val[i][j][o] = calc(j, op[p], x[p], prime[i]);
        return;
    }
    int M = (L + R) / 2;
    if(p <= M) update(o<<1, L, M, p);
    else update(o<<1|1, M+1, R, p);
    pushup(o);
}

void gcd(int a, int b, int& d, int& x, int& y) {
    if(!b) { d = a; x = 1; y = 0; }
    else { gcd(b, a%b, d, y, x); y -= x*(a/b); }
}

int a[4];
int CRT() {
    int M = 29393, d, y, x = 0;
    for(int i = 0; i < 4; i++) {
        int w = M / prime[i];
        gcd(prime[i], w, d, d, y);
        x = (x + y*w*a[i]) % M;
    }
    return (x+M)%M;
}

int main()
{
    int T; scanf("%d", &T);
    for(int kase = 1; kase <= T; kase++) {
        printf("Case #%d:\n", kase);
        scanf("%d%d", &n, &m); getchar();
        for(int i = 1; i <= n; i++) {
            scanf("%c%d", op + i, x + i);
            getchar();
        }
        build(1, 1, n);

        while(m--) {
            int cmd, p;
            scanf("%d%d", &cmd, &p);
            if(cmd == 1) {
                for(int i = 0; i < 4; i++)
                    a[i] = val[i][p%prime[i]][1];
                printf("%d\n", CRT());
            } else {
                getchar();
                scanf("%c%d", op + p, x + p);
                update(1, 1, n, p);
            }
        }
    }

    return 0;
}
