#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int maxn = 55;

int a[maxn];

int main()
{
	int n; scanf("%d", &n);
	for(int i = 0; i < n; i++) scanf("%d", a + i);
	sort(a, a + n);
	n = unique(a, a + n) - a;
	bool ok = false;
	for(int i = 2; i < n; i++)
		if(a[i]==a[i-1]+1&&a[i]==a[i-2]+2) {
			ok = true; break;
		}

	printf("%s\n", ok ? "YES" : "NO");

	return 0;
}
