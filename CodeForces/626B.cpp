#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int maxn = 200 + 10;
int n;
char s[maxn];
char color[] = "BGR";

int a[3], b[2];

int main()
{
	scanf("%d", &n);
	scanf("%s", s);
	for(int i = 0; i < n; i++) {
		if(s[i] == 'B') a[0]++;
		else if(s[i] == 'G') a[1]++;
		else a[2]++;
	}

	int cnt = 0;
	for(int i = 0; i < 3; i++) if(a[i]) cnt++;
	
	if(cnt == 3) { printf("%s\n", color); return 0; }

	if(cnt == 1) {
		for(int i = 0; i < 3; i++) if(a[i]) {
			printf("%c\n", color[i]);
			break;
		}
		return 0;
	}

	cnt = 0;
	for(int i = 0; i < 3; i++) if(a[i]) b[cnt++] = i;
	if(a[b[0]] > a[b[1]]) swap(b[0], b[1]);
	if(a[b[0]] > 1) { printf("%s\n", color); return 0; }
	int other = 3 - b[0] - b[1];
	if(a[b[1]] == 1) { printf("%c\n", color[other]); return 0; }
	int c1 = color[b[0]], c2 = color[other];
	if(c1 > c2) swap(c1, c2);
	printf("%c%c\n", c1, c2);

	return 0;
}
