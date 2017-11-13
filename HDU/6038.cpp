#include <cstdio>
#include <cstring>
#include <algorithm>
#include <map>
#include <set>
#include <vector>
#include <iostream>
#include <string>
using namespace std;
#define REP(i, a, b) for(int i = a; i < b; i++)
#define PER(i, a, b) for(int i = b - 1; i >= a; i--)
#define SZ(a) ((int)a.size())
#define MP make_pair
#define PB push_back
#define EB emplace_back
#define ALL(a) a.begin(), a.end()
typedef long long LL;
typedef pair<int, int> PII;

const int maxn = 100000 + 10;
const LL MOD = 1000000007LL;

int n, m;
int a[maxn], b[maxn], sum[maxn];
bool vis[maxn];

int main() {
	int _ = 1;
	while(scanf("%d%d", &n, &m) == 2) {
		printf("Case #%d: ", _++);
		REP(i, 0, n) scanf("%d", a + i);
		REP(i, 0, m) scanf("%d", b + i);
		memset(sum, 0, sizeof(sum));
		memset(vis, false, sizeof(vis));
		REP(i, 0, m) if(!vis[i]) {
			int l = 0;
			for(int x = i; !vis[x]; x = b[x]) {
				vis[x] = true;
				l++;
			}
			sum[l] += l;
		}
		PER(i, 1, n + 1) for(int j = i * 2; j <= n; j += i) {
			sum[j] += sum[i];
		}

		LL ans = 1;
		memset(vis, false, sizeof(vis));
		REP(i, 0, n) if(!vis[i]) {
			int l = 0;
			for(int x = i; !vis[x]; x = a[x]) {
				vis[x] = true;
				l++;
			}
			ans = ans * sum[l] % MOD;
		}

		printf("%I64d\n", ans);
	}
	
	return 0;
}


