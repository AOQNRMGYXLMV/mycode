#include <cstdio>
typedef long long LL;
LL MAX = 1LL << 62;
int gcd(int a, int b) { return !b ? a : gcd(b, a%b); }

int main()
{
	int T; scanf("%d", &T);
	while(T--) {
		int L, F, D; scanf("%d%d%d", &L, &F, &D);
		LL l = 0, r = F;
		bool ans = true;
		for(int i = 0; i < 100000; i++) {
			LL t = l % L;
			if(t + F > L) { ans = false; break; }
			l += D; r += D;
		}
		printf("%s\n", ans ? "YES" : "NO");
/*		if(!D) {
			printf("%s\n", F > L ? "NO" : "YES");
			continue;
		}
		if(F > L) { printf("NO\n"); continue; }
		if(L % gcd(L, D) == 0) printf("YES\n");
		else printf("NO\n");
		if(D <= F) {
			if(D == F) printf("%s\n", D == L ? "YES" : "NO");
			else printf("NO\n");
		}
		if(L % D == 0) { printf("YES\n"); continue; }
		if(D % L == 0) { printf("YES\n"); continue; }
		printf("NO\n");*/
	}

	return 0;
}
