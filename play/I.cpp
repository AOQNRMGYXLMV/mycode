#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#include <map>
using namespace std;

typedef pair<int, int> PII;

const int maxn = 10000 + 10;

priority_queue<int> Q;

int n, p, l;

PII a[maxn];

int main()
{
	scanf("%d", &n);
	for(int i = 1; i <= n; i++)
		scanf("%d%d", &a[i].first, &a[i].second);
	scanf("%d%d", &l, &p);
	for(int i = 1; i <= n; i++)
		a[i].first = l - a[i].first;
	sort(a + 1, a + 1 + n);

	int ans = 0, id = 1;
	bool reach = true;
	for(int pos = p; pos < l;) {
		for(; id <= n && a[id].first <= pos; id++)
			Q.push(a[id].second);
		if(Q.empty()) { reach = false; break; }
		pos += Q.top(); Q.pop(); ans++;
	}

	if(!reach) ans = -1;
	printf("%d\n", ans);

	return 0;
}
