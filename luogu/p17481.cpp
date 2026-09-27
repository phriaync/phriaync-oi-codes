#include <bits/stdc++.h>
using namespace std;
const int MAXN = 200005;

int n, m, s, t;
char c;
struct edge {
	int to;
	int next;
	int w;
}edges[MAXN << 2];
int edgecnt, edgeset[MAXN];
void addedge(int from, int to, int w) {
	edges[++edgecnt] = {to, edgeset[from], w};
	edgeset[from] = edgecnt;
}

bool ap, an, oc;
int clr[MAXN], dep[MAXN];
queue<int> q;

int main() {
	ios::sync_with_stdio(false), cin.tie(0);
	cin >> n >> m >> s >> t;
	for (int i = 1, u, v, w; i <= m; i++) {
		cin >> u >> v >> c;
		w = (c == '-' ? 0 : 1);
		addedge(u, v, w), addedge(v, u, w);
	}
	ap = an = true;
	for (int i = 1; i <= n; i++) dep[i] = -1;
	dep[s] = 0, q.push(s);
	int pres;
	while (!q.empty()) {
		pres = q.front(), q.pop();
		for (int e = edgeset[pres], to, w; e; e = edges[e].next) {
			to = edges[e].to, w = edges[e].w;
			if (w == 0) ap = false;
			else an = false;
			if (dep[to] == -1) {
				clr[to] = clr[pres] ^ 1;
				dep[to] = dep[pres] + 1;
				q.push(to);
			} else if (clr[to] == clr[pres]) oc = true;
		}
	}
	if (dep[t] == -1) cout << -1;
	else if (ap || an) cout << dep[t];
	else if (oc) cout << 0;
	else cout << clr[t];
	
	return 0;
}

/*

Let the world just slip away.

*/