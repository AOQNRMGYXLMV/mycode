#include <cstdio>
#include <cstring>
#include <algorithm>
#include <map>
#include <vector>
using namespace std;
#define REP(i, a, b) for(int i = a; i < b; i++)
#define SZ(a) ((int)a.size())
#define MP make_pair
#define ALL(a) a.begin(), a.end()
typedef long long LL;
typedef pair<int, int> PII;

const int maxn = 100000 + 10;
const int maxnode = maxn << 2;

LL k;
int n;
PII a[maxn], maxv[maxnode];
vector<int> ans;

void build(int o, int L, int R) {
    if(L == R) { maxv[o] = a[L]; return; }
    int M = (L + R) / 2;
    build(o<<1, L, M);
    build(o<<1|1, M+1, R);
    maxv[o] = max(maxv[o<<1], maxv[o<<1|1]);
}

inline int lowbit(int x) { return x&(-x); }
int C[maxn];
void add(int x, int v) {
    while(x <= n) {
        C[x] += v;
        x += lowbit(x);
    }
}
int query(int x) {
    int ans = 0;
    while(x) {
        ans += C[x];
        x -= lowbit(x);
    }
    return ans;
}

int qL = 1, qR;
PII Query(int o, int L, int R) {
    if(qL <= L && R <= qR) return maxv[o];
    int M = (L + R) / 2;
    if(qR <= M) return Query(o<<1, L, M);
    else if(qL > M) return Query(o<<1|1, M+1, R);
    else return max(Query(o<<1, L, M), Query(o<<1|1, M+1, R));
}
void update(int o, int L, int R, int p) {
    if(L == R) { maxv[o] = MP(-1, -1); return; }
    int M = (L + R) / 2;
    if(p <= M) update(o<<1, L, M, p);
    else update(o<<1|1, M+1, R, p);
    maxv[o] = max(maxv[o<<1], maxv[o<<1|1]);
}

int main() {
    scanf("%d%lld", &n, &k);
    REP(i, 1, n + 1) {
        int x; scanf("%d", &x);
        a[i] = MP(x, n - i);
    }
    build(1, 1, n);

    REP(i, 1, n + 1) {
        int lft = 1, rgh = n;
        while(lft < rgh) {
            int mid = (lft + rgh + 1) / 2;
            if(mid - query(mid) > k + 1) rgh = mid - 1;
            else lft = mid;
        }
        qR = rgh;
        PII res = Query(1, 1, n);
        ans.push_back(res.first);
        int pos = n - res.second;
		k -= pos - query(pos) - 1;
        update(1, 1, n, pos);
        add(pos, 1);
    }

    int sz = SZ(ans);
    REP(i, 0, sz - 1) printf("%d ", ans[i]);
    printf("%d\n", ans[sz - 1]);

    return 0;
}
