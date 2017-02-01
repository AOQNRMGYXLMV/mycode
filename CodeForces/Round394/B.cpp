#include <cstdio>

const int maxn = 50 + 5;

int a[maxn], b[maxn];

int main()
{
	int n, L; scanf("%d%d", &n, &L);
	for(int i = 0; i < n; i++) scanf("%d", a + i);
	a[n] = a[0] + L;
	for(int i = 0; i < n; i++) scanf("%d", b + i);
	b[n] = b[0] + L;

	for(int i = 0; i < n; i++) {
		bool flag = true;
		for(int j = 0; j < n; j++) {
			if(a[j+1]-a[j] != b[((i+j)%n)+1]-b[(i+j)%n]) {
				flag = false;
				break;
			}
		}
		if(flag) { printf("YES\n"); return 0; }
	}

	printf("NO\n");

	return 0;
}
