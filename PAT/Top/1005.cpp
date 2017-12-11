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

const int maxn = 1050000;

int a, n;
char s[maxn];

int fi[maxn], se[maxn], c[maxn], sa[maxn];

bool equal(int *a, int i, int j, int k) {
    if(a[i] != a[j]) return false;
    if(i + k < n && j + k < n) return a[i + k] == a[j + k];
    if(i + k >= n && j + k >= n) return true;
    return false;
}

void build_sa(int m = 255) {
    int *x = fi, *y = se;
    REP(i, 0, m) c[i] = 0;
    REP(i, 0, n) c[x[i] = s[i]]++;
    REP(i, 1, m) c[i] += c[i - 1];
    PER(i, 0, n) sa[--c[x[i]]] = i;
    for(int k = 1; k <= n; k <<= 1) {
        int p = 0;
        REP(i, n - k, n) y[p++] = i;
        REP(i, 0, n) if(sa[i] >= k) y[p++] = sa[i] - k;
        REP(i, 0, m) c[i] = 0;
        REP(i, 0, n) c[x[y[i]]]++;
        REP(i, 1, m) c[i] += c[i - 1];
        PER(i, 0, n) sa[--c[x[y[i]]]] = y[i];
        swap(x, y);
        p = 1; x[sa[0]] = 0;
        REP(i, 1, n)
            x[sa[i]] = equal(y, sa[i], sa[i-1], k) ? p-1 : p++;
        if(p >= n) break;
        m = p;
    }
}

int rnk[maxn], height[maxn];
void get_height() {
    REP(i, 0, n) rnk[sa[i]] = i;
    int k = 0;
    REP(i, 0, n) {
        if(k) k--;
        if(!rnk[i]) { k = 0; continue; }
        int j = sa[rnk[i] - 1];
        while(s[i+k] == s[j+k]) k++;
        height[rnk[i]] = k;
    }
}

int dp[maxn];

int main() {
	scanf("%d", &a); getchar();
	for(char c = getchar(); c != '\n'; c = getchar()) {
		s[n++] = c;
	}
	build_sa();
	get_height();

	int id = -1, maxl = 0;
	dp[0] = 0;
	if(n - sa[0] >= a) id = sa[0];
	REP(i, 1, n) {
		if(height[i] >= a) {
			dp[i] = 1;
			dp[i] += dp[i-1];
			if(dp[i] > maxl) {
				maxl = dp[i];
				id = sa[i];
			}
		} else if(!maxl && id == -1 && n - sa[i] >= a) {
			id = sa[i];
		}
	}

	REP(i, 0, a) putchar(s[id+i]);
	printf(" %d\n", maxl + 1);

	return 0;
}

