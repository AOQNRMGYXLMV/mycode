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

const int maxn = 500 + 10;

int n, a[maxn * maxn], win[maxn];
LL k;

int main() {
	scanf("%d%I64d", &n, &k);
	int maxv = -1;
	REP(i, 0, n) {
		scanf("%d", a + i);
		if(a[i] > maxv) maxv = a[i];
	}
	int tail = n, p = 1;
	REP(j, 0, n - 1) {
		if(a[0] > a[p]) {
			a[tail] = a[p];
			tail++; p++;
		} else {
			a[tail++] = a[0];
			a[0] = a[p++];
		}
		if(++win[a[0]] >= k) { printf("%d\n", a[0]); return 0; }
	}
	printf("%d\n", maxv);

	return 0;
}
