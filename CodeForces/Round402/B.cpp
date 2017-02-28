#include <cstdio>
#include <cstring>

char s[20];

int main()
{
	int k; scanf("%s %d", s, &k);
	int l = strlen(s);
	int ans = 0, cnt = 0;
	for(int i = l - 1; i >= 0; i--) {
		if(s[i] == '0') {
			cnt++;
			if(cnt >= k) break;
		} else {
			ans++;
		}
	}

	if(cnt < k) ans = l - 1;
	printf("%d\n", ans);

	return 0;
}
