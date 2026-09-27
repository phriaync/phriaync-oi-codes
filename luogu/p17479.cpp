/*

答案数组记得开够

*/

#include <bits/stdc++.h>
using namespace std;
const int MAXN = 100;

int n, m, d;
long long a[MAXN], la;

long long ans[MAXN];
int ansl;

int main() {
	ios::sync_with_stdio(false), cin.tie(0);
	cin >> n >> m >> d;
	for (int i = 1; i <= d; i++) cin >> a[i];
	long long base = 1;
	for (int i = d; i; i--) {
		la += a[i] * base;
		base *= n * m;
	}
	do {
		ans[++ansl] = la % n;
		la /= n;
	} while (la > 0);
	for (int i = ansl; i; i--) cout << ans[i] << ' ';

	return 0;
}

/*

a vacant nightfall

*/