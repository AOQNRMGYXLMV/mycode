#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int maxn = 50000 + 10;

bool vis[30];

char s[maxn];

int main()
{
	scanf("%s", s);
	int n = strlen(s);
	int r = -1;
	bool ok = false;
	for(int l = 0; l < n; l++) {
		while(r + 1 < n && r - l + 1 < 26) {
			if('A' <= s[r + 1] && s[r + 1] <= 'Z') {
				if(vis[s[r+1]-'A']) break;
				vis[s[r+1]-'A'] = true;
			}
			r++;
		}
		if(r - l + 1 == 26) {
			ok = true;
			int p = 0;
			for(int i = l; i <= r; i++) if(s[i] == '?') {
				while(vis[p]) p++;
				vis[p] = true;
				s[i] = 'A' + p;
			}
		}
		if('A' <= s[l] && s[l] <= 'Z') vis[s[l]-'A'] = false;
	}

	for(int i = 0; i < n; i++) if(s[i] == '?') s[i] = 'A';
	if(ok) printf("%s\n", s);
	else printf("-1\n");

	return 0;
}