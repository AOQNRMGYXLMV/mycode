#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;

struct Event
{
	int p, t, id;
	Event(int p, int id): p(p), t(t), id(id) {}
	bool operator < (const Event& x) const {
		return p < x.p || (p == x.p && id > x.id);
	}
};

priority_queue<Event> Q[4];

int n;
char op[5];

int main()
{
	freopen("in.txt", "r", stdin);
	while(scanf("%d", &n) == 1) {
		for(int i = 1; i <= 3; i++)
			while(!Q[i].empty()) Q[i].pop();
		int id = 0;
		while(n--) {
			scanf("%s", op);
			int a, b; scanf("%d", &a);
			if(op[0] == 'I') {
				scanf("%d", &b);
				Q[a].push(Event(b, ++id));
			} else {
				if(Q[a].empty()) puts("EMPTY");
				else {
					Event t = Q[a].top(); Q[a].pop();
					printf("%d\n", t.id);
				}
			}
		}
	}

	return 0;
}
