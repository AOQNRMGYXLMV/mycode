#include <cstdio>
#include <map>
using namespace std;

map<int, int> Map;
const int maxn = 200000 + 10;
int b[maxn], c[maxn];

int main()
{
	int n; scanf("%d", &n);
	while(n--) { int x; scanf("%d", &x); Map[x]++; }

	pair<int, int> ans(0, 0);
	scanf("%d", &n);
	for(int i = 1; i <= n; i++) scanf("%d", b + i);
	for(int i = 1; i <= n; i++) scanf("%d", c + i);
	int index = 1;
	for(int i = 1; i <= n; i++) {
		int x = Map.count(b[i]) ? Map[b[i]] : 0;
		int y = Map.count(c[i]) ? Map[c[i]] : 0;
		pair<int, int> t(x, y);
		if(t > ans) { ans = t; index = i; }
	}

	printf("%d\n", index);

	return 0;
}
