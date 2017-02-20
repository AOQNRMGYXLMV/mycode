#include <cstdio>
#include <cstring>
#include <algorithm>

int limit[26];
bool vis[26];

const int maxn = 1000 + 10;
const int MOD = 1000000007;

void add(int& a, int b) { a += b; if(a >= MOD) a -= MOD; }

int n;
char s[maxn];

int ways[maxn], mins[maxn];

bool ok(int len) {
	for(int i = 0; i < 26; i++)
		if(vis[i] && len > limit[i]) return false;
	return true;
}

int main()
{
	scanf("%d%s", &n, s + 1);
	for(int i = 0; i < 26; i++) scanf("%d", limit + i);

	int maxlen = 1;
	ways[0] = 1;
	memset(mins, 0x3f, sizeof(mins));
	mins[0] = 0;
	for(int j = 1; j <= n; j++) {
		memset(vis, false, sizeof(vis));
		for(int i = j; i > 0; i--) {
			vis[s[i] - 'a'] = true;
			if(!ok(j - i + 1)) break;
			add(ways[j], ways[i - 1]);
			if(j - i + 1 > maxlen) maxlen = j - i + 1;
			mins[j] = std::min(mins[j], mins[i - 1] + 1);
		}
	}

	printf("%d\n%d\n%d\n", ways[n], maxlen, mins[n]);

	return 0;
}
