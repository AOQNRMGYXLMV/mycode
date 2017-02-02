#include <cstdio>
#include <cstring>
#include <algorithm>
#include <bitset>
using namespace std;

const int maxn = 100000 + 5;
const int maxm = 5000 + 5;

int n, m;
char s[maxn], p[maxm];

bitset<maxn> d[2][3], eq[26];

int main()
{
	int T; scanf("%d", &T);
	while(T--) {
		scanf("%d%d", &n, &m);
		scanf("%s%s", s, p);
		for(int i = 0; i < 3; i++) d[0][i].reset();
		for(int i = 0; i < 26; i++) eq[i].reset();
		for(int i = 0; i < n; i++) eq[s[i]-'a'][i] = 1;
		d[0][1] = eq[p[0]-'a'];
		if(m > 1) d[0][2] = eq[p[1]-'a'];
		int cur = 0;
		for(int j = 1; j < m; j++) {
			cur ^= 1;
			d[cur][0] = (d[cur^1][2] >> 1) & eq[p[j-1]-'a'];
			d[cur][1] = ((d[cur^1][0] | d[cur^1][1]) >> 1) & eq[p[j]-'a'];
			if(j < m - 1) d[cur][2] = ((d[cur^1][0] | d[cur^1][1]) >> 1) & eq[p[j+1]-'a'];
		}

		for(int i = 0; i <= n - m; i++) {
			if(d[cur][0][i+m-1] | d[cur][1][i+m-1]) putchar('1');
			else putchar('0');
		}
		for(int i = 0; i < m - 1; i++) putchar('0');
		putchar('\n');
	}

	return 0;
}
