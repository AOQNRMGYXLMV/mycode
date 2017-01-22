#include <cstdio>
#include <cstring>

const int maxn = 100 + 10;
char s[maxn], color[] = "RBYG";
bool vis[4];
int id[300], ans[4];

int main()
{
	scanf("%s", s);
	int n = strlen(s);
	for(int i = 0; i < 4; i++) id[color[i]] = i;
	for(int i = 0; i < n; i++) if(s[i] != '!' && !vis[id[s[i]]]) {
		vis[id[s[i]]] = true;
		for(int j = i % 4; j < n; j += 4) if(s[j] == '!') ans[id[s[i]]]++;
	}

	for(int i = 0; i < 4; i++) printf("%d%c", ans[i], i == 3 ? '\n' : ' ');

	return 0;
}
