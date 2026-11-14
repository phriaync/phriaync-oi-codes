#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1E8+5;

int n, q, k;

int prm[MAXN], prmc;
bool nprm[MAXN];
void sieve(int n) {
	for(int i = 2; i <= n; i++) {
		if (!nprm[i]) prm[++prmc] = i;
		for (int j = 1; j <= prmc && i * prm[j] <= n; j++) {
			nprm[i * prm[j]] = true;
			if (i % prm[j] == 0) break;
		}
	}
}

int main() {
	ios::sync_with_stdio(false), cin.tie(0);
	cin >> n >> q;
	sieve(n);
	while (q--) {
		cin >> k;
		cout << prm[k] << '\n';
	}
	return 0;
}