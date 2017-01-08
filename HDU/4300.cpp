#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int maxn = 100000 + 10;

char s[30], cipher[300], decode[300];
char P[maxn], T[maxn];
int f[maxn];

void getFail(char* P) {
	f[0] = f[1] = 0;
	for(int i = 1; P[i]; i++) {
		int j = f[i];
		while(j && P[i] != P[j]) j = f[j];
		f[i + 1] = P[i] == P[j] ? j+1 : 0;
	}
}

int match(char* T, char* P) {
	int n = strlen(T), m = strlen(P);
	getFail(P);
	int j = 0;
	for(int i = 0; i < n; i++) {
		while(j && P[j] != T[i]) j = f[j];
		if(P[j] == T[i]) j++;
	}
	return j;
}

int main()
{
	int kase; scanf("%d", &kase);
	while(kase--) {
		scanf("%s", s);
		scanf("%s", P);
		for(int i = 0; i < 26; i++) {
			cipher[i + 'a'] = s[i];
			decode[s[i]] = i + 'a';
		}
		int l1 = strlen(P);
		strcpy(T, P + (l1 + 1) / 2);
		int l2 = strlen(T);
		for(int i = 0; i < l2; i++) T[i] = cipher[T[i]];

		int ans = match(T, P);
		printf("%s", P);
		for(int i = ans; i < l1 - ans; i++)
			printf("%c", decode[P[i]]);
		printf("\n");
	}

	return 0;
}
