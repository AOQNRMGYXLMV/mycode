#include <cstdio>
#include <cstring>

int cnt[1 << 10], apply[1 << 10];

void op(int& x) {
	int flag = 0;
	memset(apply, 0, sizeof(apply));
	for(int i = 0; i < (1 << 10); i++) if(cnt[i]) {
		int num = (cnt[i] + 1 - flag) >> 1;
		flag ^= cnt[i] & 1;
		apply[i] = num;
	}
	for(int i = 0; i < (1 << 10); i++) if(apply[i]) {
		int j = i ^ x;
		cnt[i] -= apply[i];
		cnt[j] += apply[i];
	}
}

int main()
{
	int n, k, x; scanf("%d%d%d", &n, &k, &x);
	while(n--) {
		int a; scanf("%d", &a);
		cnt[a]++;
	}

	for(int i = 0; i < k; i++) op(x);

	for(int i = 1023; i >= 0; i--) if(cnt[i]) { printf("%d ", i); break; }
	for(int i = 0; i < 1024; i++) if(cnt[i]) { printf("%d\n", i); break; }

	return 0;
}
