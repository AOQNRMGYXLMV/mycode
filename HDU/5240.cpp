#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

struct Exam
{
	int r, e, l;
	void read() { scanf("%d%d%d", &r, &e, &l); }
	bool operator < (const Exam& t) const {
		return e < t.e;
	}
};

const int maxn = 100000 + 10;

Exam a[maxn];

int main()
{
	int T; scanf("%d", &T);
	for(int kase = 1; kase <= T; kase++) {
		printf("Case #%d: ", kase);
		int n; scanf("%d", &n);
		for(int i = 0; i < n; i++) a[i].read();
		sort(a, a + n);
		bool flag = true;
		int time = 0, tot = 0;
		for(int i = 0; i < n; i++) {
			tot += a[i].e - time;
			time = a[i].e + a[i].l;
			if(tot < a[i].r) { flag = false; break; }
		}
		printf("%s\n", flag ? "YES" : "NO");
	}

	return 0;
}
