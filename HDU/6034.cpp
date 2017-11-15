#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
#define REP(i, a, b) for(int i = a; i < b; i++)
#define PER(i, a, b) for(int i = b - 1; i >= a; i--)
#define ALL(x) x.begin(), x.end()

const int maxn = 100000 + 10;
const LL MOD = 1000000007LL;

int a[26][maxn], r[26];
char s[maxn];
bool cmp(int i, int j) {
	PER(k, 0, maxn) {
		if(a[i][k] < a[j][k]) return true;
		else if(a[i][k] > a[j][k]) return false;
	}
	return false;
}

bool vis[26];
int value[26];

LL mul(LL a, LL b) { return a * b % MOD; }
void add(LL& a, LL b) { a += b; if(a >= MOD) a -= MOD; }

int main() {
	int n, _ = 0;
	while(scanf("%d", &n) == 1) {
		printf("Case #%d: ", ++_);
		memset(a, 0, sizeof(a));
		memset(vis, false, sizeof(vis));
		while(n--) {
			scanf("%s", s);
			int l = strlen(s);
			vis[s[0]-'a'] = true;
			PER(i, 0, l) {
				int c = s[i] - 'a';
				int p = l - i - 1;
				for(a[c][p]++; a[c][p] >= 26; p++) {
					a[c][p+1]++;
					a[c][p] -= 26;
				}
			}
		}
		REP(i, 0, 26) r[i] = i;
		sort(r, r + 26, cmp);
		
		memset(value, -1, sizeof(value));
		REP(i, 0, 26) if(!vis[r[i]]) { value[r[i]] = 0; break; }
		LL p = 1;
		REP(i, 0, 26) if(value[r[i]] == -1) value[r[i]] = p++;

		LL ans = 0;
		p = 1LL;
		REP(i, 0, maxn) {
			REP(j, 0, 26) {
				add(ans, mul(p, a[j][i] * value[j]));
			}
			p = mul(p, 26);
		}

		printf("%lld\n", ans);
	}

	return 0;
}

