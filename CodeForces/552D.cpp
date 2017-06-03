#include <cstdio>
#include <cstring>
#include <algorithm>
#include <map>
#include <set>
#include <vector>
#include <iostream>
#include <string>
using namespace std;
#define REP(i, a, b) for(int i = a; i < b; i++)
#define PER(i, a, b) for(int i = b - 1; i >= a; i--)
#define SZ(a) ((int)a.size())
#define MP make_pair
#define PB push_back
#define EB emplace_back
#define ALL(a) a.begin(), a.end()
typedef long long LL;
typedef pair<int, int> PII;

const int maxn = 500000 + 10;
const int INF = 0x3f3f3f3f;

int n, m;
inline int lowbit(int x) { return x&(-x); }
int C[maxn];

inline bool read(int &num)  
{
        char in;bool IsN=false;
        in=getchar();
        if(in==EOF) return false;
        while(in!='-'&&(in<'0'||in>'9')) in=getchar();
        if(in=='-'){ IsN=true;num=0;}
        else num=in-'0';
        while(in=getchar(),in>='0'&&in<='9'){
                num*=10,num+=in-'0';
        }
        if(IsN) num=-num;
        return true;
}

void writeln(int num){
    bool flag = false;
    if(num < 0) {
        putchar('-');
        putchar('1');
		putchar('\n');
		return;
    }
    int ans[10], top = 0;
    while(num != 0) {
        ans[top++] = num%10;
        num /= 10;
    }
    if(top == 0) putchar('0');
    for(int i = top-1; i >= 0; i--) {
        char ch = ans[i] + '0';
        putchar(ch);
    }
	putchar('\n');
}

void upd(int& a, int b) { if(a > b) a = b; }

void update(int x, int v) {
	while(x) {
		upd(C[x], v);
		x -= lowbit(x);
	}
}

int query(int x) {
	int ans = INF;
	while(x <= n) {
		upd(ans, C[x]);
		x += lowbit(x);
	}
	if(INF == ans) ans = -1;
	return ans;
}

struct Query
{
	int l, r, id;
	bool operator < (const Query& t) const {
		return r < t.r;
	}
};

PII a[maxn];
int ans[maxn], pre[maxn];
Query q[maxn];

int main() {
	scanf("%d%d", &n, &m);
	memset(C, 0x3f, sizeof(C));
	REP(i, 1, n + 1) {
		read(a[i].first);
		a[i].second = i;
	}
	sort(a + 1, a + 1 + n);
	REP(i, 2, n + 1) {
		if(a[i].first == a[i-1].first)
			pre[a[i].second] = a[i-1].second;
	}
	REP(i, 0, m) {
		//scanf("%d%d", &q[i].l, &q[i].r);
		read(q[i].l); read(q[i].r);
		q[i].id = i;
	}
	sort(q, q + m);

	int p = 1;
	REP(i, 0, m) {
		for( ;p <= q[i].r; p++) {
			if(pre[p]) update(pre[p], p - pre[p]);
		}
		ans[q[i].id] = query(q[i].l);
	}

	REP(i, 0, m) writeln(ans[i]);

	return 0;
}


