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

const int maxn = 200000 + 10;

int n, k, a[maxn];
int S[maxn], top;
bool vis[maxn];

int main() {
	scanf("%d%d", &n, &k);
	int cur = 1;
	REP(i, 0, k) {
		scanf("%d", a + i);
		vis[a[i]] = true;
		S[++top] = a[i];
		while(top && S[top] == cur) { top--; cur++; }
	}

	bool ok = true;
	REP(i, 1, top) if(S[i] < S[i+1]) { ok = false; break; }
	if(!ok) { puts("-1"); return 0; }

	REP(i, k, n) {
		a[i] = top ? S[top]-1 : n;
		S[++top] = a[i];
		while(top && S[top] == cur) { top--; cur++; }
	}

	REP(i, 0, n) printf("%d ", a[i]);
	printf("\n");

	return 0;
}

