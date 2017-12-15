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

const int maxn = 100000 + 10;

int n, a[maxn], l[maxn], pre[maxn];
vector<int> v[maxn];
int S[maxn], top;

int main() {
	scanf("%d", &n);
	pre[0] = 0;
	REP(i, 1, n + 1) {
		scanf("%d", a + i);
		pre[i] = max(pre[i-1], a[i]);
		while(top && a[S[top]] < a[i]) top--;
		l[i] = S[top];
		S[++top] = i;
		v[l[i]].PB(i);
	}

	int add = 0, choose = a[n];
	REP(i, 1, n + 1) if(l[i] == 0) {
		int t = lower_bound(ALL(v[i]), a[i]) - v[i].begin();
		t -= lower_bound(ALL(v[i]), pre[i-1]) - v[i].begin();
		if(t > add || (t == add && a[i] < choose)) {
			add = t;
			choose = a[i];
		}
	}

	printf("%d\n", choose);
	
	return 0;
}

