#include <cstdio>
#include <cstring>
#include <algorithm>

const int maxn = 1000 + 10;

char s1[maxn], s2[maxn];

int main()
{
	int n; scanf("%d", &n);
	scanf("%s%s", s1, s2);
	std::sort(s1, s1 + n);
	std::sort(s2, s2 + n);
	
	int ans1 = 0, ans2 = 0;
	for(int i = 0; i < n; i++) {
		if(s2[i] >= s1[ans1]) ans1++;
	}
	ans1 = n - ans1;

	for(int i = 0; i < n; i++) {
		if(s2[i] > s1[ans2]) ans2++;
	}

	printf("%d\n%d\n", ans1, ans2);

	return 0;
}
