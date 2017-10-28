#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
#define MP make_pair
#define PB push_back
#define REP(i, a, b) for(int i = a; i < b; i++)
#define PER(i, a, b) for(int i = b - 1; i >= a; i--)

const int maxl = 55;

int n, m;
char word[maxl], s[maxl];
int cur[maxl];
bool revealed[maxl], vis[maxl];

int main() {
	scanf("%d%s", &n, s);
	REP(i, 0, n) if(s[i] != '*') revealed[s[i]-'a'] = true;
	int cnt = 0;
	scanf("%d", &m);
	while(m--) {
		scanf("%s", word);
		bool ok = true;
		REP(i, 0, n) {
			if(s[i] == '*') {
				if(revealed[word[i]-'a']) { ok = false; break; }
			} else {
				if(word[i] != s[i]) { ok = false; break; }
			}
		}
		if(!ok) continue;
		cnt++;
		memset(vis, false, sizeof(vis));
		REP(i, 0, n) if(s[i] == '*') {
			if(!vis[word[i]-'a']) {
				vis[word[i]-'a'] = true;
				cur[word[i]-'a']++;
			}
		}
	}

	int ans = 0;
	REP(i, 0, 26) if(cur[i] == cnt) ans++;
	printf("%d\n", ans);

	return 0;
}
