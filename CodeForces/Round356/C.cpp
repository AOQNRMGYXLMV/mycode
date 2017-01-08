#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int prime[] = { 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53 };

char s[10];

int main()
{
	int minp = -1, index;
	for(int i = 0; i < 4; i++) {
		printf("%d\n", prime[i]);
		fflush(stdout);
		scanf("%s", s);
		if(s[0] == 'y') { minp = prime[i]; index = i; break; }
	}

	if(minp == -1) { printf("prime\n"); return 0; }
	for(int i = index; prime[i] * minp <= 100; i++) {
		printf("%d\n", minp * prime[i]);
		fflush(stdout);
		scanf("%s", s);
		if(s[0] == 'y') { printf("composite\n"); return 0; }
	}
	printf("prime\n");
	fflush(stdout);

	return 0;
}
