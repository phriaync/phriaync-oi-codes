#include <bits/stdc++.h>
using namespace std;
const int MAXN = 500005, MAXB = 20;

int n, m, s;
struct edge {
	int to;
	int next;
}edges[MAXN << 1];
int edgecnt, edgeset[MAXN];
void addedge(int from, int to) {
	edges[++edgecnt] = {to, edgeset[from]};
	edgeset[from] = edgecnt;
}

int fa[MAXN][MAXB], dep[MAXN];
void dfs(int pres, int prev) {
	dep[pres] = dep[prev] + 1;
	fa[pres][0] = prev;
	for (int e = edgeset[pres], to; e; e = edges[e].next) {
		to = edges[e].to;
		if (to == prev) continue;
		dfs(to, pres);
	}
}

void lca_init() {
	for (int b = 1; b < MAXB; b++) {
		for (int i = 1; i <= n; i++) {
			fa[i][b] = fa[fa[i][b - 1]][b - 1];
		}
	}
}

int lca_query(int u, int v) {
	if (dep[u] < dep[v]) swap(u, v);
	for (int b = MAXB; b; b--) {
		if (dep[fa[u][b - 1]] >= dep[v]) u = fa[u][b - 1];
	}
	if (u == v) return u;
	for (int b = MAXB; b; b--) {
		if (fa[u][b - 1] != fa[v][b - 1]) {
			u = fa[u][b - 1];
			v = fa[v][b - 1];
		}
	}
	return fa[u][0];
}

int main() {
	ios::sync_with_stdio(false), cin.tie(0);
    cin >> n >> m >> s;
	for (int i = 1, u, v; i < n; i++) {
		cin >> u >> v;
		addedge(u, v), addedge(v, u);
	}
	dfs(s, 0);
	lca_init();
	for (int i = 1, a, b; i <= m; i++) {
		cin >> a >> b;
		cout << lca_query(a, b) << '\n';
	}
	
	return 0;
}