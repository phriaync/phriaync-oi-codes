#include <bits/stdc++.h>
using namespace std;
const int MAXN = 100005, MAXB = 18;

int n, m;
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

int cnt[MAXN];
void dfsa(int pres, int prev) {
	for (int e = edgeset[pres], to; e; e = edges[e].next) {
		to = edges[e].to;
		if (to == prev) continue;
		dfsa(to, pres);
		cnt[pres] += cnt[to];
	}
}

int ans;

int main() {
	ios::sync_with_stdio(false), cin.tie(0);
    cin >> n >> m;
	for (int i = 1, u, v; i < n; i++) {
		cin >> u >> v;
		addedge(u, v), addedge(v, u);
	}
	dfs(1, 0);
	lca_init();
	for (int i = 1, a, b, x; i <= m; i++) {
		cin >> a >> b, x = lca_query(a, b);
		//cout << x << '\n';
		cnt[a]++, cnt[b]++, cnt[x] -= 2;
	}
	dfsa(1, 0);
	ans = -1;
	for (int i = 1, x; i < n; i++) {
		if (dep[edges[i * 2 - 1].to] < dep[edges[i * 2].to]) x = edges[i * 2].to;
		else x = edges[i * 2 - 1].to;
		if (cnt[x] == m) ans = i;
	}
	cout << ans;
	
	return 0;
}