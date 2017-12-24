#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
#define PB push_back
#define PII pair<int, int>
#define REP(i, a, b) for(int i = a; i < b; i++)
#define PER(i, a, b) for(int i = b - 1; i >= a; i--)
#define ALL(x) x.begin(), x.end()

const int maxn = 155;
int n;

struct Polynomial {
	int n;
	int c[maxn];

	Polynomial() { n = 0; memset(c, 0, sizeof(c)); }

	void print() {
		printf("%d\n", n);
		REP(i, 0, n) printf("%d ", c[i]);
		printf("%d\n", c[n]);
	}

	bool check() {
		REP(i, 0, n + 1) if(c[i] < -1 || c[i] > 1) return false;
		return true;
	}

	void normal() {
		REP(i, 0, n + 1) c[i] *= -1;
	}
};

void add(Polynomial& A, const Polynomial& B, int d = 1) {
	REP(i, 0, B.n+1) A.c[i] += B.c[i] * d;
}

int main() {
	scanf("%d", &n);
	
	Polynomial pa, pb;

	pa.c[0] = -1;
	REP(i, 0, n) {
		Polynomial t = pa;
		t.n++;
		PER(i, 1, t.n+1) t.c[i] = t.c[i-1];
		t.c[0] = 0;
		add(t, pb);
		if(!t.check()) add(t, pb, -2);
		pb = pa;
		pa = t;
	}
	
	if(pa.c[pa.n] < 0) { pa.normal(); pb.normal(); }
	pa.print();
	pb.print();

	return 0;
}

