#include <cstdio>
#include <cstring>
#include <algorithm>
#include <map>
#include <vector>
using namespace std;

const int N = 10000000;
const int P = 665000;
const int Q = 25000000;
typedef long long LL;
typedef pair<int, int> PII;
typedef pair<LL, int> PLI;
#define MP make_pair

LL n;
int pcnt, prime[P];
int mind[N];

void preprocess() {
	for(int i = 2; i < N; i++) {
		if(!mind[i]) { mind[i] = ++pcnt; prime[pcnt] = i; }
		for(int j = 1; j <= pcnt && 1LL * i * prime[j] < N; j++) {
			mind[i * prime[j]] = j;
			if(mind[i * prime[j]] > pcnt) { puts("Error!"); exit(0); }
			if(i % prime[j] == 0) break;
		}
	}
}

int getk(LL n) {
	int L = 1, R = pcnt;
	while(L < R) {
		int M = (L + R) / 2;
		if(1LL * prime[M] * prime[M] > n) R = M;
		else L = M + 1;
	}
	return L;
}

int C[N];
#define lowbit(x) (x&(-x))

void add(int x, int v) {
	while(x < N) {
		C[x] += v;
		x += lowbit(x);
	}
}

int sum(int x) {
	int ans = 0;
	while(x) {
		ans += C[x];
		x -= lowbit(x);
	}
	return ans;
}

map<PLI, LL> z;

int qcnt;
PII q[Q];
int ans[Q];
vector<int> vs[P];

LL solve(LL n, int j, bool fs) {
	if(!n) return 0;
	if(j == 1) return n;

	if(n < N) {
		PII p(j, (int)n);
		if(fs) {
			q[qcnt++] = p;
			return 0;
		} else {
			int x = lower_bound(q, q + qcnt, p, greater<PII>()) - q;
			return ans[x];
		}
	} else {
		PLI p(n, j);
		if(!z.count(p)) {
			LL res = solve(n, j - 1, fs);
			res -= solve(n / prime[j - 1], j - 1, fs);
			z[p] = res;
			return res;
		} else return z[p];
	}
}

void process() {
	sort(q, q + qcnt, greater<PII>());
	for(int i = 1; i <= pcnt; i++) vs[i].clear();
	for(int i = 2; i < N; i++)
		vs[mind[i]].push_back(i);

	add(1, 1);
	int p = pcnt;
	for(int i = 0, j = 0; i < qcnt; i = j) {
		while(p >= q[i].first) {
			for(int x : vs[p]) add(x, 1);
			p--;
		}

		while(j < qcnt && q[j].first == q[i].first) {
			ans[j] = sum(q[j].second);
			j++;
		}
	}
}

LL pi(LL n, bool fs) {
	int k = getk(n);
	return solve(n, k, fs) + k - 1 - 1;
}

int main()
{
	preprocess();
	scanf("%lld", &n);
	for(int i = 1; 1LL * prime[i] * prime[i] <= n; i++) {
		LL t = n / prime[i];
		if(t > prime[i]) pi(t, true);
	}

	process();
	z.clear();
	LL ans = 0;
	for(int i = 1; 1LL * prime[i] * prime[i] <= n; i++) {
		LL t = n / prime[i];
		if(t > prime[i]) {
			ans += pi(t, false);
			ans -= i;
		}
	}

	for(int i = 1; i <= pcnt && 1LL * prime[i] * prime[i] * prime[i] <= n; i++) ans++;

	printf("%lld\n", ans);

	return 0;
}
