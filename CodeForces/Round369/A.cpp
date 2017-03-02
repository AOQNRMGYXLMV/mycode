#include <cstdio>

char s[1000][6];

int main()
{
	int n; scanf("%d", &n);

	bool ok = false;
	for(int i = 0; i < n; i++) {
		scanf("%s", s[i]);
		if(!ok && s[i][0] == 'O' && s[i][1] == 'O') { ok = true; s[i][0] = s[i][1] = '+'; }
		if(!ok && s[i][3] == 'O' && s[i][4] == 'O') { ok = true; s[i][3] = s[i][4] = '+'; }
	}

	if(ok) printf("YES\n"); else { printf("NO\n"); return 0; }
	for(int i = 0; i < n; i++) printf("%s\n", s[i]);


	return 0;
}
