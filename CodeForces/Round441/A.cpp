#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int main() {
	int n, a, b, c;
	scanf("%d%d%d%d", &n, &a, &b, &c);

	if(n == 1) { printf("0\n"); return 0; }
	if(c < a && c < b) {
		printf("%d\n", min(a, b) + c * (n - 2));
	} else {
		printf("%d\n", min(a, b) * (n - 1));
	}

	return 0;
}