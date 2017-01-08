#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;

struct Message
{
	char name[100];
	int para;
	int p, id;
	bool operator < (const Message& t) const {
		return p > t.p || (p == t.p && id > t.id);
	}
};

priority_queue<Message> Q;

char op[5];

int main()
{
	int id = 0;
	while(scanf("%s", op) == 1) {
	if(op[0] == 'P') {
			Message t;
			scanf("%s", t.name);
			scanf("%d%d", &t.para, &t.p);
			t.id = ++id;
			Q.push(t);
		} else {
			if(Q.empty()) puts("EMPTY QUEUE!");
			else {
				Message t = Q.top(); Q.pop();
				printf("%s %d\n", t.name, t.para);
			}
		}
	}

	return 0;
}
