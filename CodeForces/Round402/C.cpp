#include <cstdio>
#include <cstring>
#include <algorithm>
using std::sort;

const int maxn = 200000 + 10;

struct Item
{
	int a, b, c;
	bool operator < (const Item& t) const {
		return c < t.c;
	}
};

Item a[maxn];

int main()
{
	int n, k; scanf("%d%d", &n, &k);
	for(int i = 0; i < n; i++) scanf("%d", &a[i].a);
	for(int i = 0; i < n; i++) {
		scanf("%d", &a[i].b);
		a[i].c = a[i].a - a[i].b;
	}
	sort(a, a + n);

	long long ans = 0;
	for(int i = 0; i < n; i++) {
		if(a[i].c <= 0 || i < k) ans += a[i].a;
		else ans += a[i].b;
	}

	printf("%lld\n", ans);

	return 0;
}
