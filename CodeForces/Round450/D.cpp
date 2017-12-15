#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
#define PB push_back
#define PII pair<int, int>
#define REP(i, a, b) for(int i = a; i < b; i++)
#define PER(i, a, b) for(int i = b - 1; i >= a; i--)
#define ALL(x) x.begin(), x.end()

const LL MOD = 1000000007LL;
const int maxn = 1000000 + 10;

LL mul(LL a, LL b) { return a * b % MOD; }
void add(LL& a, LL b) { a += b; if(a >= MOD) a -= MOD; }

LL pow_mod(LL a, int p) {
	LL ans = 1;
	while(p) {
		if(p & 1) ans = mul(ans, a);
		a = mul(a, a);
		p >>= 1;
	}
	return ans;
}

int mu[maxn];
int pcnt, prime[maxn];
bool vis[maxn];

void preprocess() {
	mu[1] = 1;
	REP(i, 2, maxn) {
		if(!vis[i]) { mu[i] = -1; prime[pcnt++] = i; }
		REP(j, 0, pcnt) {
			LL prod = (LL)prime[j] * i;
			if(prod >= maxn) break;
			vis[prod] = true;
			if(i % prime[j] == 0) {
				mu[prod] = 0;
				break;
			}
			mu[prod] = -mu[i];
		}
	}
}

int calc(int x) {
	//if(x < maxn) return mu[x];
	int ans = 1;
	for(int i = 0; (LL)prime[i] * prime[i] <= x; i++) if(x % prime[i] == 0) {
		ans *= -1;
		x /= prime[i];
		if(x % prime[i] == 0) return 0;
	}
	if(x > 1) ans *= -1;
	return ans;
}

int main() {
	preprocess();
	int x, y; scanf("%d%d", &x, &y);
	if(y % x != 0) { printf("0\n"); return 0; }
	y /= x;

	LL ans = 0;
	for(int i = 1; i * i <= y; i++) if(y % i == 0) {
		add(ans, mul(mu[i], pow_mod(2, y/i - 1)));
		if(i * i != y) {
			add(ans, mul(calc(y/i), pow_mod(2, i-1)));
		}
	}
	
	printf("%lld\n", ans);

	return 0;
}

