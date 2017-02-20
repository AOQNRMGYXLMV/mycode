#include <cstdio>
#include <cstring>
#include <map>

using std::string;

const int maxn = 100000 + 10;

map<string, int> ID;

int n, m, q;

int pa[maxn * 2];
int findset(int x) { return x == pa[x] ? x : pa[x] = findset(pa[x]); }
void Union(int u, int v) {
	int pu = findset(u), pv = findset(v);
	if(pu != pv) pa[pu] = pv;
}

int main()
{
	scanf("%d%d%d", &n, &m, &q);
	char word[30];
	for(int i = 1; i <= n; i++) {
		scanf("%s", word);
		ID[word] = i;
	}

	int cc = 0;
	for(int i = 0; i < m; i++) {
		int t; char word1[30], word2[30];
		scanf("%d%s%s", &t, word1, word2); t--;
		int u = ID[word1], v = ID[word2];
		int pu = findset(u), pv = findset(v);
		if(!pu && !pv) {
			c++;
			pa[u] = (c << 1) + n;
			pa[v] = ((c << 1) ^ t) + n;
			printf("YES\n");
		} else if(pu && !pv) {
			pa[v] = ((pu - n) ^ t) + n;
			printf("YES\n");
		} else if(!pu && pv) {
			pa[u] = ((pv - n) ^ t) + n;
			printf("YES\n");
		} else {
			if(1 == ((pu - n) ^ (pv - n) ^ t)) printf("YES\n");
			else printf("NO\n");

		}
	}

	return 0;
}
