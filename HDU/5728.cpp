#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;

typedef long long LL;

const int MOD = 1000000007;
const int maxn = 10000000 + 10;

LL mul_mod(LL a, LL b) { return a * b % MOD; }

bool vis[maxn];
int phi[maxn], sum[maxn];
int pcnt, prime[670000];

void pre() {
	for(int i = 2; i < maxn; i++) {
		if(!vis[i]) { prime[pcnt++] = i; phi[i] = i - 1; }
		for(int j = 0; j < pcnt && (LL)i * prime[j] < maxn; j++) {
			vis[i * prime[j]] = true;
			if(i % prime[j] == 0) {
				phi[i * prime[j]] = phi[i] * prime[j];
				break;
			} else {
				phi[i * prime[j]] = phi[i] * (prime[j] - 1);
			}
		}
	}

	phi[1] = 1;
	for(int i = 1; i < maxn; i++) {
		sum[i] = sum[i - 1] + phi[i];
		if(sum[i] >= MOD) sum[i] -= MOD;
	}
}

vector<int> factor;

LL f(LL n, LL m, int pos) {
	if(!m) return 0;
	if(m == 1) return phi[n];
	if(n == 1) return sum[m];
	int p = factor[pos];
	return (mul_mod(phi[p], f(n / p, m, pos + 1)) + f(n, m / p, pos)) % MOD;
}

LL pow_mod(LL a, int p, int m) {
	LL ans = 1;
	while(p) {
		if(p & 1) ans = ans * a % m;
		a = a * a % m;
		p >>= 1;
	}
	return ans % m;
}

LL solve(LL k, int p) {
	if(p == 1) return 0;
	if(p == 2) return (k & 1);
	return pow_mod(k, solve(k, phi[p]) + phi[p], p);
}

int main()
{
	pre();
	int n, m, p;
	while(scanf("%d%d%d", &n, &m, &p) == 3) {
		factor.clear();
		int x = n;
		for(int i = 0; prime[i] * prime[i] <= n; i++) {
			if(x % prime[i] == 0) {
				factor.push_back(prime[i]);
				x /= prime[i];
			}
		}
		if(x > 1) factor.push_back(x);
		
		LL k = f(n, m, 0);

		printf("%lld\n", solve(k, p));
	}

	return 0;
}
