#include <cstdio>
#include <cstring>
#include <algorithm>
#include <map>
#include <vector>
using namespace std;
#define REP(i, a, b) for(int i = a; i < b; i++)
#define PER(i, a, b) for(int i = b - 1; i >= a; i--)
#define SZ(a) ((int)a.size())
#define fi first
#define se second
#define MP make_pair
#define ALL(a) a.begin(), a.end()
typedef long long LL;
typedef pair<int, int> PII;

void upd(LL& a, LL b) { if(a < b) a = b; }

const int maxn = 100000 + 10;

int n, x, k;
PII a[maxn];

int main() {
    scanf("%d%d%d", &n, &x, &k);
    REP(i, 0, n) scanf("%d%d", &a[i].fi, &a[i].se);
    sort(a, a + n);
    
    LL ans = 0;
    
    int p = upper_bound(a, a + n, MP(x, 0x3f3f3f3f)) - a;
    
    //only consider left
    if(p) {
        LL t = 0;
        PER(i, 0, p) {
            if(x - a[i].fi > k) break;
            t += a[i].se;
        }
        upd(ans, t);
    }
    
    //only consider right
    if(p < n) {
        LL t = 0;
        REP(i, p, n) {
            if(a[i].fi - x > k) break;
            t += a[i].se;
        }
        upd(ans, t);
    }
    
    if(p == 0 || p == n) { printf("%lld\n", ans); return 0; }
    
    //go left first then turn back
    LL value = a[p - 1].se + a[p].se;
    int L = p - 1, R = p;
    if(x + a[p].fi - a[p - 1].fi * 2 <= k) {
        while(R + 1 < n && a[R + 1].fi + x - a[L].fi * 2 <= k) { R++; value += a[R].se; }
        for(L = p - 1; L >= 0; L--) {
            if(x + a[p].fi - a[L].fi * 2 > k) break;
            while(x + a[R].fi - a[L].fi * 2 > k) { value -= a[R].se; R--; }
            upd(ans, value);
            if(L) value += a[L - 1].se;
        }
    }

    //go right first then turn back
    value = a[p - 1].se + a[p].se;
    L = p - 1; R = p;
    if(a[p].fi * 2 - a[p - 1].fi - x <= k) {
        while(L && a[R].fi * 2 - x - a[L - 1].fi <= k) { L--; value += a[L].se; }
        for(R = p; R < n; R++) {
            if(a[R].fi * 2 - x - a[p - 1].fi > k) break;
            while(a[R].fi * 2 - x - a[L].fi > k) { value -= a[L].se; L++; }
            upd(ans, value);
            if(R + 1 < n) value += a[R + 1].se;
        }
    }

    printf("%lld\n", ans);

    return 0;
}
