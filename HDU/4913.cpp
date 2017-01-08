#include <cstdio>
#include <cstring>
#include <algorithm>
#include <map>
using namespace std;

typedef pair<int, int> PII;
typedef long long LL;
const int maxn = 100000 + 10;
const LL MOD = 1000000007;

int n;
PII a[maxn];

bool cmp(int i, int j) {
    return (a[i].second < a[j].second) || (a[i].second == a[j].second && i < j);
}

int p[maxn], r[maxn];

struct BIT
{
    int C[maxn];

    void init() { memset(C, 0, sizeof(C)); }

    int lowbit(int x) { return x & (-x); }

    void add(int x, int val) {
        while(x <= n) {
            C[x] += val;
            x += lowbit(x);
        }
    }

    int query(int x) {
        int ans = 0;
        while(x) {
            ans += C[x];
            x -= lowbit(x);
        }
        return ans;
    }
};

BIT bit;

LL mul(LL a, LL b) { return a * b % MOD; }

LL add(LL a, LL b) { a += b; if(a >= MOD) a -= MOD; return a; }

LL pow_mod(LL a, int p) {
	LL ans = 1;
	while(p) {
		if(p & 1) ans = mul(ans, a);
		a = mul(a, a);
		p >>= 1;
	}
	return ans;
}

LL sumv[maxn << 2];
int powv[maxn << 2];

void pushdown(int o) {
	if(powv[o]) {
		LL t = pow_mod(2LL, powv[o]);
		sumv[o<<1]   = mul(sumv[o<<1], t);
		sumv[o<<1|1] = mul(sumv[o<<1|1], t);
		powv[o<<1] += powv[o];
		powv[o<<1|1] += powv[o];
		powv[o] = 0;
	}
}

void pushup(int o) {
	sumv[o] = add(sumv[o<<1], sumv[o<<1|1]);
}

void update_mul(int o, int L, int R, int qL, int qR) {
	if(qL <= L && R <= qR) {
		sumv[o] = mul(sumv[o], 2);
		powv[o]++;
		return;
	}
	pushdown(o);
	int M = (L + R) / 2;
	if(qL <= M) update_mul(o<<1, L, M, qL, qR);
	if(qR > M) update_mul(o<<1|1, M+1, R, qL, qR);
	pushup(o);
}

void update_add(int o, int L, int R, int p, LL val) {
	if(L == R) {
		sumv[o] = add(sumv[o], val);
		return;
	}
	pushdown(o);
	int M = (L + R) / 2;
	if(p <= M) update_add(o<<1, L, M, p, val);
	else update_add(o<<1|1, M+1, R, p, val);
	pushup(o);
}

LL query(int o, int L, int R, int qL, int qR) {
	if(qL <= L && R <= qR) return sumv[o];
	pushdown(o);
	int M = (L + R) / 2;
	LL ans = 0;
	if(qL <= M) ans = add(ans, query(o<<1, L, M, qL, qR));
	if(qR > M) ans = add(ans, query(o<<1|1, M+1, R, qL, qR));
	return ans;
}

int main()
{
    while(scanf("%d", &n) == 1) {
        for(int i = 1; i <= n; i++) {
            scanf("%d%d", &a[i].first, &a[i].second);
            p[i] = i;
        }
        sort(a + 1, a + 1 + n);
        sort(p + 1, p + 1 + n, cmp);
		for(int i = 1; i <= n; i++) r[p[i]] = i;

		bit.init();
        memset(sumv, 0, sizeof(sumv));
		memset(powv, 0, sizeof(powv));

		LL ans = 0;
		for(int i = 1; i <= n; i++) {
			int x = bit.query(r[i]);
			LL a2 = pow_mod(2, a[i].first);
			LL x2 = pow_mod(2, x);
			LL b3 = pow_mod(3, a[i].second);

			LL add1 = mul(x2, b3);
			LL add2 = query(1, 1, n, r[i], n);
			ans = add(ans, mul(a2, add(add1, add2)));
			update_add(1, 1, n, r[i], mul(x2, b3));
			if(x < i - 1) update_mul(1, 1, n, r[i] + 1, n);
			bit.add(r[i], 1);
		}

		printf("%lld\n", ans);
    }

    return 0;
}
