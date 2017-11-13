#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
#define MP make_pair
#define PB push_back
#define REP(i, a, b) for(int i = a; i < b; i++)
#define PER(i, a, b) for(int i = b - 1; i >= a; i--)

const int maxn = 100000 + 10;

int n, m, k;
int a[maxn], S[maxn], cnt[maxn], top;

int main() {
	bool single_color = true;
	scanf("%d%d%d", &n, &k, &m);
	REP(i, 0, n) scanf("%d", a + i);
	REP(i, 1, n) if(a[i] != a[i - 1]) { single_color = false; break; }

	if(single_color) {
		printf("%I64d\n", (LL)n * m % k);
		return 0;
	}

	REP(i, 0, n) {
		S[++top] = a[i];
		if(top > 1 && S[top] == S[top-1]) cnt[top] = cnt[top-1] + 1;
		else cnt[top] = 1;
		if(cnt[top] >= k) top -= k;
	}

	int L = 1, R = top;
	LL t = 0;

	while(S[L] == S[R] && L < R) {
		int l = L, r = R, cnt = 0;
		while(S[l] == S[L] && l < r && cnt < k) { cnt++; l++; }
		while(S[r] == S[L] && l < r && cnt < k) { cnt++; r--; }
		if(cnt == k) { L = l; R = r; t += k; }
		else break;
	}

	single_color = true;
	REP(i, L, R) if(S[i] != S[i+1]) { single_color = false; break; }
	if(single_color) {
		LL mid = (LL)(R-L+1)*m%k;
		if(mid) printf("%lld\n", mid + t);
		else printf("0\n");
	} else {
		printf("%lld\n", (LL)(R-L+1)*m + t);
	}

	return 0;
}