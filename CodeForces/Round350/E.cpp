#include <cstdio>

const int maxn = 500000 + 10;
char s[maxn], op[maxn];
int p[maxn], l[maxn], r[maxn];

int main()
{
	int n, m, pos; scanf("%d%d%d", &n, &m, &pos);
	scanf("%s%s", s + 1, op);
	int top = 0;
	for(int i = 1; i <= n; i++) {
		if(s[i] == '(') l[top++] = i;
		else { p[i] = l[--top]; p[l[top]] = i; }
	}

	for(int i = 0; i <= n; i++) {
		l[i + 1] = i;
		r[i] = i + 1;
	}

	for(int i = 0; i < m; i++) {
		if(op[i] == 'L') {
			if(l[pos]) pos = l[pos];
		} else if(op[i] == 'R') {
			if(r[pos] <= n) pos = r[pos];
		} else {
			if(p[pos] < pos) pos = p[pos];
			if(!l[pos] && r[p[pos]] > n) continue;
			r[l[pos]] = r[p[pos]];
			l[r[p[pos]]] = l[pos];
			if(r[p[pos]] <= n) pos = r[p[pos]];
			else pos = l[pos];
		}
	}

	for(int i = r[0]; i <= n; i = r[i]) printf("%c", s[i]);
	printf("\n");

	return 0;
}
