#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
#define MP make_pair
#define PB push_back
#define REP(i, a, b) for(int i = a; i < b; i++)
#define PER(i, a, b) for(int i = b - 1; i >= a; i--)

int state[10];

int operate(char op, int x, int y) {
	if(op == '&') return x & y;
	if(op == '|') return x | y;
	return x ^ y;
}

int main() {
	REP(i, 0, 10) state[i] = 2;
	int n; scanf("%d", &n);
	char op[5];
	int x;
	while(n--) {
		scanf("%s %d", op, &x);
		REP(i, 0, 10) {
			int t = (x >> i) & 1;
			if(op[0] == '^') state[i] ^= t;
			else if(op[0] == '&') {
				if(!t) state[i] = 0;
			} else {
				if(t) state[i] = 1;
			}

		}
	}

	printf("3\n");
	x = (1 << 10) - 1;
	REP(i, 0, 10) if(state[i] == 0) x ^= (1 << i);
	printf("& %d\n", x);
	x = 0;
	REP(i, 0, 10) if(state[i] == 1) x ^= (1 << i);
	printf("| %d\n", x);
	x = 0;
	REP(i, 0, 10) if(state[i] == 3) x ^= (1 << i);
	printf("^ %d\n", x);

	return 0;
}
