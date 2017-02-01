#include <cstdio>
#include <cstring>
#include <algorithm>
#include <map>
using namespace std;

typedef long long LL;
const LL MOD = 1000000007LL;
const int maxn = 1000 + 10;

struct Point
{
    LL x, y;
    Point(LL x = 0, LL y = 0): x(x), y(y) {}
    void read() { scanf("%lld%lld", &x, &y); }
};

bool operator < (const Point& A, const Point& B) {
    return A.x < B.x || (A.x == B.x && A.y < B.y);
}

bool operator == (const Point& A, const Point& B) {
    return A.x == B.x && A.y == B.y;
}

Point operator - (const Point& A, const Point& B) {
    return Point(A.x - B.x, A.y - B.y);
}

Point operator / (const Point& A, int p) {
    return Point(A.x / p, A.y / p);
}

LL Cross(const Point& A, const Point& B) {
    return A.x * B.y - A.y * B.x;
}

int n;
Point p[maxn], q[maxn];

map<int, int> cnt;
map<Point, int> num;

LL pow_mod(LL a, int p) {
    LL ans = 1;
    while(p) {
        if(p & 1) ans = ans * a % MOD;
        a = a * a % MOD;
        p >>= 1;
    }
    return ans;
}

bool cmp(Point A, Point B) {
    return Cross(A, B) > 0;
}

int gcd(int a, int b) { return !b ? a : gcd(b, a%b); }

void add(LL& a, LL b) { a += b; if(a >= MOD) a -= MOD; }

LL mul(LL a, LL b) { return a * b % MOD; }

int main()
{
    int T; scanf("%d", &T);
    while(T--) {
        cnt.clear();
        scanf("%d", &n);
        for(int i = 0; i < n; i++) {
            p[i].read();
            cnt[p[i].x]++;
        }
        sort(p, p + n);
        LL ans = 0;
        for(int i = 0; i < n; i++) {
            int eq, st;
            for(eq = i; eq + 1 < n && p[eq + 1] == p[i]; eq++);
            for(st = eq + 1; st < n && p[st].x == p[i].x; st++);
            LL A = pow(2, eq - i + 1);
            add(A, MOD - 1);
            num.clear();
            for(int j = st; j < n; j++) {
                Point v = p[j] - p[i];
                int g = gcd(v.x, v.y);
                v = v / g;
                num[v]++;
            }
            for(auto it = num.begin(); it != num.end(); it++) {
                LL B = pow_mod(2, it->second);
                add(B, MOD - 1);
                add(ans, mul(A, B));
            }
            i = eq;
        }
        for(auto it = cnt.begin(); it != cnt.end(); it++) {
            LL t = pow_mod(2, it->second);
            add(ans, t);
            add(ans, MOD - 1 - it->second);
        }
        
        printf("%lld\n", ans);
    }

    return 0;
}
