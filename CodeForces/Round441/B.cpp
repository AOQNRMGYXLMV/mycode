#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

const int maxn = 100000 + 10;

int n, k, m;
vector<int> c[maxn];

int main() {
	scanf("%d%d%d", &n, &k, &m);
	for(int i = 0; i < n; i++) {
		int x; scanf("%d", &x);
		c[x % m].push_back(x / m);
	}
	for(int i = 0; i < m; i++) {
		if((int)c[i].size() >= k) {
			printf("Yes\n");
			for(int j = 0; j < k; j++)
				printf("%d ", c[i][j] * m + i);
			printf("\n");
			return 0;
		}
	}
	printf("No\n");

	return 0;
}