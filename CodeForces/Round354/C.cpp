#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int maxn = 100000 + 10;

char s[maxn];

int main()
{
	int n, k; scanf("%d%d", &n, &k);
	scanf("%s", s + 1);
	int ans = 0;
	
	int cnt = 0;
	int L = 0, R = 0;
	for(L = 1; L <= n; L++) {
		//if(R < L - 1) R = L - 1;
		while(R < n) {
			if(s[R + 1] == 'b' && cnt == k) break;
			R++;
			if(s[R] == 'b') cnt++;
		}
		ans = max(ans, R - L + 1);
		if(s[L] == 'b') cnt--;
	}

	cnt = L = R = 0;
	for(L = 1; L <= n; L++) {
		//if(R < L - 1) R = L - 1;
		while(R < n) {
			if(s[R + 1] == 'a' && cnt == k) break;
			R++;
			if(s[R] == 'a') cnt++;
		}
		ans = max(ans, R - L + 1);
		if(s[L] == 'a') cnt--;
	}

	printf("%d\n", ans);

	return 0;
}
